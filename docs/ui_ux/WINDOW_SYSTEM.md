# Window System - Snapping, Z-Order and Management

> **EVE Online-Style Window Management for Echoes MMO**  
> Draggable, resizable, focusable UI windows with intelligent snapping

---

## Overview

The Echoes window system provides a robust, user-friendly interface for managing multiple UI panels simultaneously, inspired by EVE Online's window management paradigm.

## Core Features

### 1. Window Dragging
- Click and drag title bar to move windows anywhere on screen
- Smooth, responsive dragging with mouse capture
- Windows stay within viewport bounds

### 2. Window Resizing
- Drag bottom-right corner to resize
- Minimum and maximum size constraints
- Proportional scaling of content
- Real-time content reflow

### 3. Focus Management (Z-Order)
- Click any part of window to bring to front
- Automatic Z-order management
- Visual feedback for focused window (highlighted border)
- Unfocused windows dimmed slightly

### 4. Window Snapping
- Snap to screen edges (Top, Bottom, Left, Right)
- Snap to other windows (Magnetic attraction)
- Snap threshold: 20 pixels
- Visual snap indicators

### 5. Window Docking (Future)
- Dock windows to screen edges
- Tabbed window groups
- Persistent dock layouts

---

## Architecture

### Class Hierarchy

```
UUserWidget (Unreal Base Class)
    ↓
UEchoesWindowBase (Base Window Class)
    ↓
UEchoesInventoryWindow
UEchoesShipFittingWindow
UEchoesOverviewWindow
UEchoesCharacterSheetWindow
```

### File Structure

```
Client/Echoes/Source/Echoes/UI/
├── EchoesWindowBase.h/.cpp          # Base window class
├── EchoesWindowManager.h/.cpp       # Global window management
├── EchoesInventoryWindow.h/.cpp     # Inventory window
├── EchoesFittingWindow.h/.cpp       # Ship fitting window
└── EchoesOverviewWindow.h/.cpp      # Overview/scanner window
```

---

## Implementation Details

### UEchoesWindowBase

**Purpose:** Base class for all draggable/resizable windows

**Key Properties:**
```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
FText WindowTitle;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
FVector2D MinimumSize = FVector2D(300, 200);

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
FVector2D MaximumSize = FVector2D(1920, 1080);

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bCanResize = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bCanClose = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bSnapToEdges = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bSnapToWindows = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
float SnapThreshold = 20.0f;
```

**Key Methods:**
```cpp
// Called when window is opened
virtual void NativeConstruct() override;

// Mouse interaction
virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, 
                                       const FPointerEvent& InMouseEvent) override;
virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, 
                                     const FPointerEvent& InMouseEvent) override;
virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, 
                                 const FPointerEvent& InMouseEvent) override;

// Window management
void BringToFront();
void CloseWindow();
void SetWindowPosition(FVector2D NewPosition);
void SetWindowSize(FVector2D NewSize);

// Snapping
FVector2D CalculateSnappedPosition(FVector2D DesiredPosition);
bool ShouldSnapToEdge(FVector2D Position, FVector2D& SnappedPosition);
bool ShouldSnapToWindow(FVector2D Position, UEchoesWindowBase* OtherWindow, FVector2D& SnappedPosition);
```

---

## Dragging Logic

### State Machine

```
Idle State
    ↓ [Mouse Down on Title Bar]
Dragging State
    ↓ [Mouse Move]
Update Position (with snapping)
    ↓ [Mouse Up]
Idle State
```

### Implementation

```cpp
FReply UEchoesWindowBase::NativeOnMouseButtonDown(const FGeometry& InGeometry, 
                                                   const FPointerEvent& InMouseEvent)
{
    // Check if clicking on title bar
    if (IsTitleBarHit(InGeometry, InMouseEvent))
    {
        bIsDragging = true;
        
        // Calculate offset from mouse to window position
        FVector2D MousePosition = InMouseEvent.GetScreenSpacePosition();
        FVector2D WindowPosition = GetCachedGeometry().GetAbsolutePosition();
        DragOffset = WindowPosition - MousePosition;
        
        // Bring window to front
        BringToFront();
        
        // Capture mouse
        return FReply::Handled().CaptureMouse(this->TakeWidget());
    }
    
    return FReply::Handled();
}

FReply UEchoesWindowBase::NativeOnMouseMove(const FGeometry& InGeometry, 
                                             const FPointerEvent& InMouseEvent)
{
    if (bIsDragging)
    {
        // Calculate desired position
        FVector2D MousePosition = InMouseEvent.GetScreenSpacePosition();
        FVector2D DesiredPosition = MousePosition + DragOffset;
        
        // Apply snapping
        FVector2D SnappedPosition = CalculateSnappedPosition(DesiredPosition);
        
        // Clamp to viewport bounds
        SnappedPosition = ClampToViewport(SnappedPosition);
        
        // Update window position
        SetWindowPosition(SnappedPosition);
        
        return FReply::Handled();
    }
    
    return FReply::Unhandled();
}

FReply UEchoesWindowBase::NativeOnMouseButtonUp(const FGeometry& InGeometry, 
                                                 const FPointerEvent& InMouseEvent)
{
    if (bIsDragging)
    {
        bIsDragging = false;
        
        // Release mouse capture
        return FReply::Handled().ReleaseMouseCapture();
    }
    
    return FReply::Handled();
}
```

---

## Snapping System

### Edge Snapping

**Algorithm:**
```cpp
bool UEchoesWindowBase::ShouldSnapToEdge(FVector2D Position, FVector2D& SnappedPosition)
{
    if (!bSnapToEdges) return false;
    
    FVector2D ViewportSize = GEngine->GameViewport->Viewport->GetSizeXY();
    FVector2D WindowSize = GetDesiredSize();
    
    bool bSnapped = false;
    SnappedPosition = Position;
    
    // Snap to left edge
    if (FMath::Abs(Position.X) < SnapThreshold)
    {
        SnappedPosition.X = 0;
        bSnapped = true;
    }
    
    // Snap to right edge
    if (FMath::Abs((Position.X + WindowSize.X) - ViewportSize.X) < SnapThreshold)
    {
        SnappedPosition.X = ViewportSize.X - WindowSize.X;
        bSnapped = true;
    }
    
    // Snap to top edge
    if (FMath::Abs(Position.Y) < SnapThreshold)
    {
        SnappedPosition.Y = 0;
        bSnapped = true;
    }
    
    // Snap to bottom edge
    if (FMath::Abs((Position.Y + WindowSize.Y) - ViewportSize.Y) < SnapThreshold)
    {
        SnappedPosition.Y = ViewportSize.Y - WindowSize.Y;
        bSnapped = true;
    }
    
    return bSnapped;
}
```

### Window-to-Window Snapping

**Algorithm:**
```cpp
bool UEchoesWindowBase::ShouldSnapToWindow(FVector2D Position, 
                                            UEchoesWindowBase* OtherWindow, 
                                            FVector2D& SnappedPosition)
{
    if (!bSnapToWindows || !OtherWindow) return false;
    
    FVector2D OtherPos = OtherWindow->GetWindowPosition();
    FVector2D OtherSize = OtherWindow->GetWindowSize();
    FVector2D ThisSize = GetDesiredSize();
    
    bool bSnapped = false;
    SnappedPosition = Position;
    
    // Snap to other window's right edge
    float DistToRightEdge = FMath::Abs(Position.X - (OtherPos.X + OtherSize.X));
    if (DistToRightEdge < SnapThreshold)
    {
        SnappedPosition.X = OtherPos.X + OtherSize.X;
        bSnapped = true;
    }
    
    // Snap to other window's left edge
    float DistToLeftEdge = FMath::Abs((Position.X + ThisSize.X) - OtherPos.X);
    if (DistToLeftEdge < SnapThreshold)
    {
        SnappedPosition.X = OtherPos.X - ThisSize.X;
        bSnapped = true;
    }
    
    // Similar logic for top/bottom snapping...
    
    return bSnapped;
}
```

---

## Z-Order Management

### UEchoesWindowManager

**Purpose:** Global manager for all windows and Z-order

**Singleton Pattern:**
```cpp
UCLASS()
class UEchoesWindowManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()
    
private:
    // All active windows, sorted by Z-order (back to front)
    UPROPERTY()
    TArray<UEchoesWindowBase*> ActiveWindows;
    
    int32 NextZOrder = 1000;
    
public:
    // Register window when opened
    void RegisterWindow(UEchoesWindowBase* Window);
    
    // Unregister window when closed
    void UnregisterWindow(UEchoesWindowBase* Window);
    
    // Bring window to front
    void BringWindowToFront(UEchoesWindowBase* Window);
    
    // Get all windows for snapping calculations
    TArray<UEchoesWindowBase*> GetAllWindows() const { return ActiveWindows; }
};
```

### Z-Order Algorithm

```cpp
void UEchoesWindowManager::BringWindowToFront(UEchoesWindowBase* Window)
{
    if (!Window) return;
    
    // Remove from current position
    ActiveWindows.Remove(Window);
    
    // Add to end (highest Z)
    ActiveWindows.Add(Window);
    
    // Assign Z-orders
    for (int32 i = 0; i < ActiveWindows.Num(); ++i)
    {
        int32 ZOrder = NextZOrder + i;
        ActiveWindows[i]->SetZOrder(ZOrder);
    }
    
    NextZOrder += ActiveWindows.Num();
}
```

---

## Resizing Logic

### Resize Handle

**Visual:** Small triangle icon in bottom-right corner

**Hit Detection:**
```cpp
bool UEchoesWindowBase::IsResizeHandleHit(const FGeometry& InGeometry, 
                                          const FPointerEvent& InMouseEvent)
{
    FVector2D LocalMousePos = InGeometry.AbsoluteToLocal(
        InMouseEvent.GetScreenSpacePosition()
    );
    
    FVector2D WindowSize = InGeometry.GetLocalSize();
    FVector2D HandlePos = WindowSize - FVector2D(20, 20);
    FVector2D HandleSize = FVector2D(20, 20);
    
    return LocalMousePos.X >= HandlePos.X && 
           LocalMousePos.Y >= HandlePos.Y;
}
```

### Resize Algorithm

```cpp
void UEchoesWindowBase::UpdateResize(const FPointerEvent& InMouseEvent)
{
    if (!bIsResizing) return;
    
    FVector2D MousePosition = InMouseEvent.GetScreenSpacePosition();
    FVector2D WindowPosition = GetWindowPosition();
    
    // Calculate new size
    FVector2D NewSize = MousePosition - WindowPosition;
    
    // Apply constraints
    NewSize.X = FMath::Clamp(NewSize.X, MinimumSize.X, MaximumSize.X);
    NewSize.Y = FMath::Clamp(NewSize.Y, MinimumSize.Y, MaximumSize.Y);
    
    // Update size
    SetWindowSize(NewSize);
}
```

---

## Widget Structure

### Required Widget Hierarchy

```
Canvas Panel (Root)
└─ Border (WindowContainer) ← Z-order controlled
   ├─ Border (FocusHighlight) ← Shows when focused
   └─ Vertical Box
      ├─ Border (TitleBar) ← Draggable area
      │  └─ Horizontal Box
      │     ├─ Image (WindowIcon)
      │     ├─ Text Block (TitleText)
      │     ├─ Spacer
      │     ├─ Button (MinimizeButton) [_]
      │     └─ Button (CloseButton) [X]
      ├─ Border (ContentBorder)
      │  └─ Named Slot (ContentSlot) ← Content goes here
      └─ Image (ResizeHandle) ← Bottom-right corner
```

### Blueprint Setup

1. **Create Widget Blueprint** inheriting from `UEchoesWindowBase`
2. **Add required widgets** with exact names:
   - `TitleBar` (Border)
   - `TitleText` (TextBlock)
   - `CloseButton` (Button)
   - `ContentSlot` (NamedSlot)
   - `ResizeHandle` (Image)
   - `FocusHighlight` (Border)
3. **Bind in C++:**
```cpp
void UEchoesWindowBase::NativeConstruct()
{
    Super::NativeConstruct();
    
    // Bind widgets
    TitleBar = Cast<UBorder>(GetWidgetFromName(TEXT("TitleBar")));
    TitleText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TitleText")));
    CloseButton = Cast<UButton>(GetWidgetFromName(TEXT("CloseButton")));
    
    // Set title
    if (TitleText)
    {
        TitleText->SetText(WindowTitle);
    }
    
    // Bind close button
    if (CloseButton)
    {
        CloseButton->OnClicked.AddDynamic(this, &UEchoesWindowBase::OnCloseButtonClicked);
    }
    
    // Register with window manager
    auto WindowManager = GetGameInstance()->GetSubsystem<UEchoesWindowManager>();
    WindowManager->RegisterWindow(this);
}
```

---

## Usage Examples

### Opening Inventory Window

```cpp
void AEchoesPlayerController::OpenInventoryWindow()
{
    if (InventoryWindowClass)
    {
        // Create widget
        auto InventoryWindow = CreateWidget<UEchoesInventoryWindow>(
            this, InventoryWindowClass
        );
        
        // Set initial position (center of screen)
        FVector2D ViewportSize = GEngine->GameViewport->Viewport->GetSizeXY();
        FVector2D WindowSize = FVector2D(800, 600);
        FVector2D Position = (ViewportSize - WindowSize) * 0.5f;
        
        InventoryWindow->SetWindowPosition(Position);
        InventoryWindow->SetWindowSize(WindowSize);
        
        // Add to viewport
        InventoryWindow->AddToViewport();
    }
}
```

### Cascading Windows

```cpp
void OpenCascadingWindows()
{
    FVector2D StartPosition = FVector2D(100, 100);
    FVector2D Offset = FVector2D(30, 30);
    
    for (int32 i = 0; i < 3; ++i)
    {
        auto Window = CreateWindow();
        Window->SetWindowPosition(StartPosition + Offset * i);
        Window->AddToViewport();
    }
}
```

---

## Future Enhancements

### Planned Features

1. **Window Docking**
   - Dock to screen edges
   - Persistent dock layouts
   - Tabbed window groups

2. **Window Transparency**
   - Semi-transparent unfocused windows
   - Click-through option

3. **Window Animations**
   - Smooth open/close animations
   - Minimize to taskbar

4. **Keyboard Shortcuts**
   - Alt+F4 to close
   - Win+Arrow for snap positions

5. **Multi-Monitor Support**
   - Windows persist across monitors
   - Remember monitor placement

---

## Performance Considerations

### Optimization Tips

1. **Minimize Tick Usage**
   - Use event-driven updates instead of Tick
   - Only update when dragging/resizing

2. **Widget Pool**
   - Reuse window widgets instead of creating new ones
   - Keep inactive windows hidden, not destroyed

3. **Z-Order Batching**
   - Batch Z-order changes
   - Update only when necessary

---

**Last Updated:** 2026-01-31  
**Status:** Implemented  
**Version:** 1.0
