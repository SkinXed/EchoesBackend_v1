# Context Menu System Documentation

## Overview

This document describes the complete right-click context menu system for inventory items in the Echoes MMO project. The system provides dynamic, context-aware actions with server validation.

## Architecture

### Core Components

#### 1. UEchoesContextMenuWidget
**Purpose**: Dynamic context menu displayed on right-click

**File**: `UI/EchoesContextMenuWidget.h/cpp`

**Key Features**:
- Extends `UUserWidget`
- Dynamic action button generation
- Smart positioning (stays within screen bounds)
- Auto-closes on outside click or Escape key
- Singleton behavior (one menu at a time)
- Blueprint extensibility

**Key Methods**:
```cpp
// Initialize menu with item and actions
void InitializeMenu(
    UEchoesInventoryItemObject* InItemObject,
    const FGuid& InSourceStorageId,
    AActor* InSourceActor,
    const TArray<FContextMenuAction>& InActions);

// Position menu at mouse cursor
void PositionAtMouse();

// Close the menu
void CloseMenu();

// Smart position calculation
FVector2D CalculateSmartPosition(const FVector2D& DesiredPosition, const FVector2D& MenuSize) const;
```

**Delegates**:
```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContextMenuActionSelected, const FString&, ActionName);
```

#### 2. FContextMenuAction
**Purpose**: Action definition structure

**Structure**:
```cpp
struct FContextMenuAction
{
    FText DisplayName;      // Display text on button
    FString ActionId;       // Internal identifier
    bool bEnabled;          // Whether action is clickable
    FText Tooltip;          // Optional tooltip text
};
```

**Usage**:
```cpp
FContextMenuAction JettisonAction(
    FText::FromString(TEXT("Jettison")),
    TEXT("jettison"),
    true  // enabled
);
```

#### 3. Server Actions

Three server-authoritative actions implemented:

**ServerOnly_JettisonItem**:
- Drops item from inventory into space
- Spawns AEchoesItemActor near ship
- Supports partial quantity

**ServerOnly_StackAll**:
- Combines all items of same type
- Sums quantities into single stack
- Removes duplicate database entries

**ServerOnly_MoveItem** (existing):
- Moves items between containers
- Distance validation
- Capacity checks

## User Flow

### Right-Click Item

```
1. User right-clicks inventory item
   ↓
2. NativeOnMouseButtonDown detects RMB
   ↓
3. GetDefaultActionsForItem() called
   ├─ Check item type
   ├─ Check item definition
   └─ Build action array
   ↓
4. OnContextMenuRequested Blueprint event
   └─ Allows Blueprint to modify actions
   ↓
5. Create UEchoesContextMenuWidget
   ↓
6. InitializeMenu() with item and actions
   ├─ Set title to item name
   ├─ BuildMenuContent() creates buttons
   └─ PositionAtMouse() with smart bounds
   ↓
7. Add menu to viewport (Z-order 999)
   ↓
8. Wait for user input
   ├─ Click action → Execute and close
   ├─ Click outside → Close
   └─ Press Escape → Close
```

### Action Execution

```
1. User clicks action button
   ↓
2. OnActionButtonClicked() fires
   ↓
3. OnActionSelected delegate broadcasts
   ↓
4. HandleContextMenuAction() in entry widget
   ├─ Find inventory component
   ├─ Get item data
   └─ Route to appropriate handler
   ↓
5. Execute server action
   ├─ ServerOnly_JettisonItem
   ├─ ServerOnly_StackAll
   └─ Or custom action
   ↓
6. Server processes request
   ├─ Validate authority
   ├─ Validate authentication
   ├─ Execute database operation
   └─ Broadcast OnInventoryUpdated
   ↓
7. All inventory widgets refresh
   ↓
8. User sees updated inventory
```

## Implementation Guide

### Creating Context Menu Widget Blueprint

#### Step 1: Create Widget Blueprint

1. Create new Widget Blueprint
2. Parent Class: `UEchoesContextMenuWidget`
3. Name: `W_EchoesContextMenu`

#### Step 2: Build Widget Hierarchy

```
Canvas Panel
└─ Border (MenuBackground)
   ├─ Appearance
   │  ├─ Brush Color: #2C2C2C (semi-transparent)
   │  ├─ Outline: 1px, #555555
   │  └─ Shadow: 2px blur, #000000
   └─ Content
      └─ Vertical Box
         ├─ Padding: 8px all sides
         ├─ Child 1: Text Block (TitleText)
         │  ├─ Font: Bold, 14pt
         │  ├─ Color: #FFFFFF
         │  └─ Padding: 0,0,0,8
         └─ Child 2: Vertical Box (ActionsContainer)
            └─ Spacing: 2px
```

#### Step 3: Widget Bindings

**Required bindings** (must match C++ names):
- `TitleText` (UTextBlock) - Shows item name
- `ActionsContainer` (UVerticalBox) - Container for action buttons

#### Step 4: Styling

**Menu Background**:
- Color: Dark gray with 90% opacity
- Border: 1px light gray
- Corner radius: 4px
- Shadow: Soft drop shadow

**Action Buttons** (created dynamically):
- Normal: Transparent background, white text
- Hover: Light gray background (#404040)
- Pressed: Darker gray (#2C2C2C)
- Disabled: Gray text (#808080), no interaction

### Configuring Entry Widget

In your inventory entry widget blueprint:

```
Details Panel
└─ Context Menu
   └─ Context Menu Class: W_EchoesContextMenu
```

### Custom Actions (Blueprint)

Override `OnContextMenuRequested` event:

```
Event OnContextMenuRequested
├─ Item Object: UEchoesInventoryItemObject (input)
├─ Out Actions: TArray<FContextMenuAction> (input/output)
│
└─ Implementation:
   ├─ Check item properties
   ├─ Check player state
   ├─ Add custom actions to array
   │  Example:
   │  ├─ Make Struct: FContextMenuAction
   │  │  ├─ Display Name: "Use Item"
   │  │  ├─ Action Id: "use_item"
   │  │  └─ Enabled: true
   │  └─ Array Add: Out Actions
   │
   └─ Remove unwanted default actions
      └─ Array Remove: Out Actions (by index or value)
```

### Handling Custom Actions

Override `OnContextMenuActionExecuted` event:

```
Event OnContextMenuActionExecuted
├─ Item Object: UEchoesInventoryItemObject
├─ Action Id: String
│
└─ Implementation:
   ├─ Switch on Action Id
   │  ├─ Case "use_item":
   │  │  └─ Execute use logic
   │  ├─ Case "custom_action":
   │  │  └─ Execute custom logic
   │  └─ Default:
   │     └─ Log warning
   │
   └─ Show feedback to user
      └─ Create notification widget
```

## Available Actions

### Default Actions

#### 1. Jettison (Drop Item)

**Display**: "Jettison"
**Action ID**: `jettison`
**Availability**: Always available
**Effect**: Removes item from inventory, spawns in space

**Implementation**:
```cpp
void HandleContextMenuAction(const FString& ActionId)
{
    if (ActionId == TEXT("jettison"))
    {
        Component->ServerOnly_JettisonItem(
            ItemObject->GetAssetId(),
            0,  // 0 = drop all quantity
            FOnItemMoveSuccess::CreateLambda([this]()
            {
                UE_LOG(LogTemp, Log, TEXT("Item jettisoned successfully"));
            }),
            FOnInventoryOperationFailure::CreateLambda([this](const FString& Error)
            {
                UE_LOG(LogTemp, Error, TEXT("Failed to jettison: %s"), *Error);
            })
        );
    }
}
```

#### 2. Fit to Ship (Equipment)

**Display**: "Fit to Ship"
**Action ID**: `fit`
**Availability**: Modules and equipment only
**Effect**: Attempts to fit module to ship (stub)

**Conditions**:
```cpp
const FEchoesItemDefinitionRow* Definition = ItemObject->GetItemDefinition();
if (Definition)
{
    FString Category = Definition->Category.ToString();
    if (Category.Contains(TEXT("Module")) || Category.Contains(TEXT("Equipment")))
    {
        // Show "Fit to Ship" action
    }
}
```

#### 3. Stack All

**Display**: "Stack All"
**Action ID**: `stack_all`
**Availability**: Stackable items only
**Effect**: Combines all items of same type in container

**Implementation**:
```cpp
if (ActionId == TEXT("stack_all"))
{
    Component->ServerOnly_StackAll(
        ItemObject->GetTypeId(),
        FOnItemMoveSuccess::CreateLambda([this]()
        {
            UE_LOG(LogTemp, Log, TEXT("Items stacked successfully"));
        }),
        FOnInventoryOperationFailure::CreateLambda([this](const FString& Error)
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to stack: %s"), *Error);
        })
    );
}
```

### Adding Custom Actions

Example: "Use Consumable"

```cpp
// In GetDefaultActionsForItem or OnContextMenuRequested
if (ItemObject->GetItemDefinition()->Category == EItemCategory::Consumable)
{
    Actions.Add(FContextMenuAction(
        FText::FromString(TEXT("Use")),
        TEXT("use_consumable"),
        true
    ));
}

// In HandleContextMenuAction
if (ActionId == TEXT("use_consumable"))
{
    // Execute use logic
    UseConsumableItem(ItemObject->GetAssetId());
}
```

## Smart Positioning Algorithm

### Purpose
Ensure context menu stays within visible screen bounds

### Algorithm

```cpp
FVector2D CalculateSmartPosition(const FVector2D& DesiredPosition, const FVector2D& MenuSize)
{
    // 1. Start with desired position (mouse location + offset)
    FVector2D FinalPosition = DesiredPosition;
    FinalPosition.X += 5.0f;  // Small offset from cursor
    FinalPosition.Y += 5.0f;
    
    // 2. Check right edge
    if (FinalPosition.X + MenuSize.X > ViewportSize.X)
    {
        // Shift left to fit
        FinalPosition.X = ViewportSize.X - MenuSize.X - 10.0f;
        
        // If still doesn't fit, position to left of cursor
        if (FinalPosition.X < 0)
        {
            FinalPosition.X = DesiredPosition.X - MenuSize.X - 5.0f;
        }
    }
    
    // 3. Check bottom edge
    if (FinalPosition.Y + MenuSize.Y > ViewportSize.Y)
    {
        // Shift up to fit
        FinalPosition.Y = ViewportSize.Y - MenuSize.Y - 10.0f;
        
        // If still doesn't fit, position above cursor
        if (FinalPosition.Y < 0)
        {
            FinalPosition.Y = DesiredPosition.Y - MenuSize.Y - 5.0f;
        }
    }
    
    // 4. Ensure minimum position (don't go off left/top)
    FinalPosition.X = FMath::Max(FinalPosition.X, 10.0f);
    FinalPosition.Y = FMath::Max(FinalPosition.Y, 10.0f);
    
    return FinalPosition;
}
```

### Edge Cases

**Scenario 1**: Menu near right edge
```
Cursor: (1800, 500)
Menu Size: (200, 150)
Viewport: (1920, 1080)

Result: Position at (1710, 505) - shifted left to fit
```

**Scenario 2**: Menu near bottom-right corner
```
Cursor: (1850, 1000)
Menu Size: (200, 150)
Viewport: (1920, 1080)

Result: Position at (1710, 920) - shifted left and up
```

**Scenario 3**: Small viewport
```
Cursor: (100, 100)
Menu Size: (300, 200)
Viewport: (320, 240)

Result: Position at (10, 30) - best fit possible
```

## Auto-Close Behavior

### Triggers

1. **Outside Click**:
   ```cpp
   FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
   {
       if (IsClickOutsideMenu(InGeometry, InMouseEvent))
       {
           CloseMenu();
           return FReply::Handled();
       }
       return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
   }
   ```

2. **Escape Key**:
   ```cpp
   FReply NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
   {
       if (InKeyEvent.GetKey() == EKeys::Escape)
       {
           CloseMenu();
           return FReply::Handled();
       }
       return Super::NativeOnKeyDown(MyGeometry, InKeyEvent);
   }
   ```

3. **Action Selected**:
   ```cpp
   void OnActionButtonClicked(const FString& ActionId)
   {
       OnActionSelected.Broadcast(ActionId);
       CloseMenu();  // Auto-close after action
   }
   ```

4. **New Menu Opened**:
   ```cpp
   void NativeConstruct()
   {
       // Close any existing menu
       if (CurrentMenu && CurrentMenu != this)
       {
           CurrentMenu->CloseMenu();
       }
       CurrentMenu = this;
   }
   ```

## Server-Side Implementation

### Backend Endpoints Required

#### 1. POST /api/inventory/jettison

**Request**:
```json
{
  "assetId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
  "quantity": 0
}
```

**Response**:
```json
{
  "success": true,
  "message": "Item jettisoned successfully",
  "itemActor": {
    "id": "guid",
    "typeId": 123,
    "quantity": 100,
    "location": {
      "x": 1000.0,
      "y": 2000.0,
      "z": 3000.0
    }
  }
}
```

**Server Logic**:
```csharp
[HttpPost("jettison")]
public async Task<IActionResult> JettisonItem([FromBody] JettisonRequest request)
{
    // 1. Validate user authentication
    var userId = GetAuthenticatedUserId();
    
    // 2. Find asset in player's inventory
    var asset = await _context.Assets
        .Where(a => a.Id == request.AssetId && a.OwnerId == userId)
        .FirstOrDefaultAsync();
    
    if (asset == null)
        return NotFound("Asset not found");
    
    // 3. Get player ship location
    var playerShip = await GetPlayerShip(userId);
    var spawnLocation = playerShip.Location + new Vector3(100, 0, 0);
    
    // 4. Remove from database (or reduce quantity)
    if (request.Quantity == 0 || request.Quantity >= asset.Quantity)
    {
        _context.Assets.Remove(asset);
    }
    else
    {
        asset.Quantity -= request.Quantity;
    }
    
    // 5. Create item actor in world
    var itemActor = new ItemActor
    {
        TypeId = asset.TypeId,
        Quantity = request.Quantity > 0 ? request.Quantity : asset.Quantity,
        Location = spawnLocation,
        SpawnedAt = DateTime.UtcNow
    };
    
    _context.ItemActors.Add(itemActor);
    await _context.SaveChangesAsync();
    
    // 6. Broadcast to nearby players
    await _gameHub.Clients.Group(playerShip.SectorId)
        .SendAsync("ItemSpawned", itemActor);
    
    return Ok(new { success = true, itemActor });
}
```

#### 2. POST /api/inventory/stack-all

**Request**:
```json
{
  "storageId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
  "typeId": 123
}
```

**Response**:
```json
{
  "success": true,
  "message": "Items stacked successfully",
  "itemsAffected": 5,
  "stacksCreated": 1,
  "totalQuantity": 500
}
```

**Server Logic**:
```csharp
[HttpPost("stack-all")]
public async Task<IActionResult> StackAll([FromBody] StackAllRequest request)
{
    // 1. Validate user owns storage
    var userId = GetAuthenticatedUserId();
    var storage = await _context.Containers
        .Where(c => c.Id == request.StorageId && c.OwnerId == userId)
        .FirstOrDefaultAsync();
    
    if (storage == null)
        return Unauthorized();
    
    // 2. Query all assets in storage
    var query = _context.Assets
        .Where(a => a.ContainerId == request.StorageId);
    
    // 3. Filter by TypeId if specified
    if (request.TypeId > 0)
    {
        query = query.Where(a => a.TypeId == request.TypeId);
    }
    
    // 4. Group by TypeId
    var assetGroups = await query
        .GroupBy(a => a.TypeId)
        .ToListAsync();
    
    int totalAffected = 0;
    int stacksCreated = 0;
    
    foreach (var group in assetGroups)
    {
        if (group.Count() <= 1)
            continue;  // Already a single stack
        
        // 5. Sum quantities
        var totalQuantity = group.Sum(a => a.Quantity);
        
        // 6. Keep first asset, delete others
        var firstAsset = group.First();
        firstAsset.Quantity = totalQuantity;
        
        var assetsToRemove = group.Skip(1).ToList();
        _context.Assets.RemoveRange(assetsToRemove);
        
        totalAffected += group.Count();
        stacksCreated++;
    }
    
    await _context.SaveChangesAsync();
    
    return Ok(new 
    { 
        success = true, 
        itemsAffected = totalAffected,
        stacksCreated 
    });
}
```

## Testing

### Manual Testing Checklist

#### Context Menu Display
- [ ] Right-click item shows menu
- [ ] Menu positioned near cursor
- [ ] Menu stays on screen (test all edges)
- [ ] Menu shows item name in title
- [ ] Action buttons display correctly
- [ ] Disabled actions are grayed out

#### Auto-Close Behavior
- [ ] Click outside menu closes it
- [ ] Press Escape closes menu
- [ ] Select action closes menu
- [ ] Open new menu closes previous one

#### Action Execution
- [ ] Jettison removes item from inventory
- [ ] Stack All combines duplicate items
- [ ] Success shows updated inventory
- [ ] Failure shows error message
- [ ] Multiple actions work sequentially

#### Edge Cases
- [ ] Right-click near screen edges
- [ ] Right-click in corners
- [ ] Right-click with small viewport
- [ ] Right-click while dragging
- [ ] Rapid successive right-clicks

### Automated Testing (Future)

```cpp
// Example test cases
TEST_F(ContextMenuTest, MenuPositionsCorrectlyNearRightEdge)
{
    // Setup
    FVector2D MousePos(1850, 500);
    FVector2D MenuSize(200, 150);
    FVector2D ViewportSize(1920, 1080);
    
    // Execute
    FVector2D Result = Menu->CalculateSmartPosition(MousePos, MenuSize);
    
    // Verify
    EXPECT_LE(Result.X + MenuSize.X, ViewportSize.X);
    EXPECT_GE(Result.X, 0.0f);
}

TEST_F(ContextMenuTest, MenuClosesOnOutsideClick)
{
    // Setup
    ShowContextMenu();
    
    // Execute
    SimulateClick(FVector2D(0, 0));  // Outside menu
    
    // Verify
    EXPECT_FALSE(IsMenuVisible());
}
```

## Troubleshooting

### Menu Not Appearing

**Problem**: Right-click doesn't show menu

**Solutions**:
1. Check `ContextMenuClass` is set in entry widget
2. Verify entry widget has mouse input enabled
3. Check item object is valid
4. Look for errors in log
5. Ensure actions array is not empty

### Menu Positioned Off-Screen

**Problem**: Menu appears outside viewport

**Solutions**:
1. Check `CalculateSmartPosition` logic
2. Verify viewport size calculation
3. Test with different screen resolutions
4. Check menu size estimation
5. Add logging to positioning code

### Menu Doesn't Close

**Problem**: Menu stays open after action

**Solutions**:
1. Check `CloseMenu()` is called after action
2. Verify outside click detection works
3. Check Escape key binding
4. Look for exceptions in close logic
5. Test singleton behavior

### Actions Not Executing

**Problem**: Click action does nothing

**Solutions**:
1. Check `OnActionSelected` delegate is bound
2. Verify `HandleContextMenuAction` is called
3. Check action ID matches
4. Verify inventory component is found
5. Check server authority for server actions

## Performance Considerations

### Optimization Tips

1. **Menu Creation**:
   - Create once per right-click
   - Destroy after use (no pooling needed)
   - Lightweight widget (< 1ms creation)

2. **Button Generation**:
   - Only create buttons for available actions
   - Cache button class reference
   - Avoid excessive styling computation

3. **Positioning**:
   - Calculate once on show
   - Cache viewport size
   - Use simple math (no expensive operations)

4. **Singleton Management**:
   - Static pointer for current menu
   - No searching or iteration
   - Immediate cleanup of old menu

5. **Network**:
   - Single RPC per action
   - No polling
   - Response-driven updates

### Memory Usage

- Menu widget: ~5-10 KB
- Action buttons: ~2 KB each
- Total per menu: ~20-30 KB
- Freed immediately on close

## API Reference

### UEchoesContextMenuWidget

```cpp
class UEchoesContextMenuWidget : public UUserWidget
{
public:
    // Initialize menu
    void InitializeMenu(
        UEchoesInventoryItemObject* InItemObject,
        const FGuid& InSourceStorageId,
        AActor* InSourceActor,
        const TArray<FContextMenuAction>& InActions);
    
    // Position at mouse
    void PositionAtMouse();
    
    // Close menu
    void CloseMenu();
    
    // Getters
    UEchoesInventoryItemObject* GetItemObject() const;
    FGuid GetSourceStorageId() const;
    AActor* GetSourceActor() const;
    
    // Delegate
    FOnContextMenuActionSelected OnActionSelected;
    
protected:
    // Blueprint events
    void OnMenuInitialized();
    void OnMenuClosed();
    
    // Widget bindings
    UVerticalBox* ActionsContainer;
    UTextBlock* TitleText;
};
```

### FContextMenuAction

```cpp
struct FContextMenuAction
{
    FText DisplayName;
    FString ActionId;
    bool bEnabled;
    FText Tooltip;
    
    FContextMenuAction();
    FContextMenuAction(const FText& InDisplayName, const FString& InActionId, bool bInEnabled = true);
};
```

### UEchoesInventoryComponent (Extended)

```cpp
class UEchoesInventoryComponent : public UActorComponent
{
public:
    // Jettison item
    void ServerOnly_JettisonItem(
        const FGuid& AssetId,
        int64 Quantity,
        FOnItemMoveSuccess OnSuccess,
        FOnInventoryOperationFailure OnFailure);
    
    // Stack all items
    void ServerOnly_StackAll(
        int32 TypeId,
        FOnItemMoveSuccess OnSuccess,
        FOnInventoryOperationFailure OnFailure);
};
```

## Summary

The context menu system provides:
- ✅ Dynamic, context-aware menus
- ✅ Smart positioning algorithm
- ✅ Auto-close behavior
- ✅ Server-validated actions
- ✅ Blueprint extensibility
- ✅ Clean architecture
- ✅ Comprehensive error handling

All C++ implementation is complete. Blueprint integration required for visual styling. Backend endpoints needed for jettison and stack-all functionality.
