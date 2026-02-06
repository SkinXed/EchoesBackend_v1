# Space HUD - UMG Hierarchy and Blueprint Integration Guide

## Overview

This guide provides detailed UMG widget hierarchy and Blueprint integration examples for all four Space HUD modules. Each module is designed to be used both in C++ and Blueprint with full customization support.

## Module 1: Overview Widget - UMG Hierarchy

### Widget Blueprint Structure (WBP_Overview)

```
[Canvas Panel] (Root)
├─ [Vertical Box] - Main Container
│  │
│  ├─ [Horizontal Box] - Header Section
│  │  ├─ [Text Block] "HeaderText" - "Overview (0)"
│  │  └─ [Spacer]
│  │
│  ├─ [Horizontal Box] - Sort Buttons
│  │  ├─ [Button] "SortDistanceButton"
│  │  │  └─ [Text Block] "Distance ↓"
│  │  ├─ [Button] "SortNameButton"
│  │  │  └─ [Text Block] "Name"
│  │  ├─ [Button] "SortTypeButton"
│  │  │  └─ [Text Block] "Type"
│  │  └─ [Button] "FilterButton"
│  │     └─ [Text Block] "Filter"
│  │
│  └─ [List View] "OverviewListView" - Main List
│     └─ Entry Widget Class: WBP_OverviewRow
```

### Row Entry Widget (WBP_OverviewRow)

```
[Horizontal Box] (Root) - Size: Fill
├─ [Image] "IconImage" - 32x32
├─ [Text Block] "NameText" - 200px wide
├─ [Spacer] - Fill
├─ [Text Block] "DistanceText" - 100px wide, Right Aligned
└─ [Text Block] "VelocityText" - 100px wide, Right Aligned
```

### Blueprint Setup (WBP_Overview)

**Event Graph**:
```
Event Construct
  ↓
Get Player Controller
  ↓
Cast to EchoesPlayerController
  ↓
Get Pawn
  ↓
Store as Player Ship Reference
  ↓
Start Populate Timer (5 seconds repeating)


OnSelectionChanged (Overview Widget)
  ↓
Get Selected Row Data
  ↓
Call "Set Navigation Target" on Navigation Widget


OnItemDoubleClicked (Overview Widget)
  ↓
Get Player Targeting Component
  ↓
ServerRPC_StartLock(Target Actor)
```

### Adding Entities to Overview (Blueprint Function)

```
Function: PopulateOverview
  ↓
Get All Actors of Class (AShip)
  ↓
For Each Actor
  │ ↓
  │ Create FOverviewRowData
  │ │ Entity ID = GetUniqueID
  │ │ Actor Reference = Actor
  │ │ Entity Name = GetName
  │ │ Distance = Calc Distance
  │ │ Entry Type = Determine Type (see logic below)
  │ ↓
  │ AddEntry(RowData) → Overview Widget
  ↓
End


Determine Type Logic:
  If Is Player → Player
  Else If Same Team → Friendly
  Else If At War → Hostile
  Else → Neutral
```

## Module 2: Target Panel Widget - UMG Hierarchy

### Widget Blueprint Structure (WBP_TargetPanel)

```
[Vertical Box] (Root)
├─ [Horizontal Box] - Header
│  ├─ [Text Block] "HeaderText" - "Targets (0/5)"
│  └─ [Button] "ClearAllButton" - "X"
│
└─ [Scroll Box]
   └─ [Vertical Box] "TargetContainer" - Dynamic Children
      └─ Entry Widget Class: WBP_TargetItem (spawned dynamically)
```

### Target Item Widget (WBP_TargetItem)

```
[Overlay] (Root) - 300x150
│
├─ [Canvas Panel] - Background Layer
│  └─ [Image] - Background (semi-transparent)
│
├─ [Canvas Panel] - Lock Progress Ring
│  └─ [Circular Throbber] "LockProgressRing" - 120x120, Centered
│     OR [Image] with Radial Material
│
└─ [Vertical Box] - Content Layer
   ├─ [Horizontal Box] - Header
   │  ├─ [Text Block] "TargetNameText" - Bold, 16pt
   │  └─ [Text Block] "DistanceText" - 12pt, Right
   │
   ├─ [Spacer] - 10px
   │
   └─ [Vertical Box] - Health Bars
      ├─ [Horizontal Box] - Shield
      │  ├─ [Text Block] "Shield:"
      │  ├─ [Progress Bar] "ShieldBar" - Blue
      │  └─ [Text Block] "ShieldText" - "100%"
      │
      ├─ [Horizontal Box] - Armor
      │  ├─ [Text Block] "Armor:"
      │  ├─ [Progress Bar] "ArmorBar" - Yellow
      │  └─ [Text Block] "ArmorText" - "100%"
      │
      └─ [Horizontal Box] - Hull
         ├─ [Text Block] "Hull:"
         ├─ [Progress Bar] "HullBar" - Red
         └─ [Text Block] "HullText" - "100%"
```

### Blueprint Setup (WBP_TargetPanel)

**Event Graph**:
```
Event Construct
  ↓
Get Player Pawn
  ↓
Find Component by Class (UTargetingComponent)
  ↓
Branch: Valid?
  ↓ Yes
  BindToTargetingComponent(Targeting Component)
```

**Custom Events** (inherited from C++):
```
OnTargetStateChanged (Target, TargetData)
  ↓
Print Debug Info (optional)
  ↓
Play Sound "Target Updated"


OnTargetSelected (Target)
  ↓
Set as Primary Target
  ↓
Update Navigation Widget Target
```

### Lock Progress Ring Material

Create material **M_LockProgressRing**:

**Material Nodes**:
```
[TexCoord] → [Subtract (0.5,0.5)] → [Length] → Store as "Dist"

[Time] → [Sine] → [Multiply 0.5] → [Add 0.5] → Store as "Pulse"

[Progress Parameter (Scalar)] → Compare with Angle
  ↓
If (Angle < Progress * 2 * PI) → Show Color
Else → Transparent

Final: Lerp(Transparent, LockColor, Mask)
```

Apply to Image widget in WBP_TargetItem with Dynamic Material Instance.

## Module 3: Ship Status Widget - UMG Hierarchy

### Widget Blueprint Structure (WBP_ShipStatus)

```
[Overlay] (Root) - 400x400
│
├─ [Canvas Panel] - Radial Bars Layer
│  │
│  ├─ [Image] "ShieldBar" - 400x400
│  │  └─ Material: M_RadialBar_Shield
│  │     Parameters: Progress, InnerRadius=0.75, OuterRadius=0.9
│  │
│  ├─ [Image] "ArmorBar" - 400x400
│  │  └─ Material: M_RadialBar_Armor
│  │     Parameters: Progress, InnerRadius=0.55, OuterRadius=0.7
│  │
│  ├─ [Image] "HullBar" - 400x400
│  │  └─ Material: M_RadialBar_Hull
│  │     Parameters: Progress, InnerRadius=0.35, OuterRadius=0.5
│  │
│  └─ [Image] "CapacitorBar" - 400x400
│     └─ Material: M_RadialBar_Capacitor
│        Parameters: Progress, InnerRadius=0.0, OuterRadius=0.3
│
└─ [Vertical Box] - Text Overlays (Centered)
   ├─ [Text Block] "ShieldText" - "Shield: 1.2k / 3.5k"
   ├─ [Text Block] "ArmorText" - "Armor: 800 / 1.2k"
   ├─ [Text Block] "HullText" - "Hull: 450 / 650"
   └─ [Text Block] "CapacitorText" - "Cap: 250 / 500"
```

### Radial Bar Material (M_RadialBar)

**Material Parameters**:
- `Progress` (Scalar, 0-1)
- `FillColor` (Vector 3, RGB)
- `InnerRadius` (Scalar, 0-1)
- `OuterRadius` (Scalar, 0-1)

**Material Graph**:
```
[TexCoord]
  ↓
Subtract (0.5, 0.5) - Center
  ↓
[Length] → Store as "Distance"
[ArcTangent2] → Normalize to 0-1 → Store as "Angle"
  ↓
Mask by Progress:
  If (Angle < Progress && Distance > InnerRadius && Distance < OuterRadius)
    → FillColor
  Else
    → Transparent
  ↓
Output to Emissive Color
Output Alpha
```

### Blueprint Setup (WBP_ShipStatus)

**Event Graph**:
```
Event Construct
  ↓
Get Player Pawn
  ↓
BindToShip(Player Pawn)
  ↓
Create Dynamic Material Instances for all bars
  ↓
Store DMI references


Event Tick (or Timer)
  ↓
Get Ship Data (IShipStateInterface)
  ↓
Update Shield Material Instance
  │ Set Scalar Parameter "Progress" = ShieldPct
  │ Set Vector Parameter "FillColor" = GetHealthColor(ShieldPct)
  ↓
Update Armor Material Instance
  │ Set Scalar Parameter "Progress" = ArmorPct
  │ Set Vector Parameter "FillColor" = GetHealthColor(ArmorPct)
  ↓
Update Hull Material Instance
  │ Set Scalar Parameter "Progress" = HullPct
  │ Set Vector Parameter "FillColor" = GetHealthColor(HullPct)
  ↓
Update Capacitor Material Instance
  │ Set Scalar Parameter "Progress" = CapacitorPct
  │ Set Vector Parameter "FillColor" = (0, 0.7, 1) - Cyan
```

**Custom Event: OnHullChanged** (called from C++):
```
OnHullChanged (NewPct, OldPct)
  ↓
Branch: NewPct < 0.25 (CRITICAL)
  ↓ Yes
  Play Sound "Hull Warning"
    ↓
  Start Flashing Animation
    ↓
  Set HullBar Color to Pulsing Red
```

## Module 4: Navigation Widget - UMG Hierarchy

### Widget Blueprint Structure (WBP_Navigation)

```
[Vertical Box] (Root)
│
├─ [Overlay] - Speed Display
│  │
│  ├─ [Canvas Panel] - Speedometer Background
│  │  └─ [Image] - Circular gauge bg
│  │
│  └─ [Vertical Box] - Speed Text
│     ├─ [Text Block] "SpeedText" - "125 m/s" (48pt, Bold)
│     ├─ [Text Block] "MaxSpeedText" - "Max: 350 m/s" (12pt)
│     └─ [Progress Bar] "SpeedBar" - Horizontal, Thin
│
├─ [Spacer] - 20px
│
├─ [Overlay] - Velocity Vector (Optional)
│  │
│  ├─ [Image] - Compass background (circle)
│  ├─ [Image] "VelocityArrow" - Arrow sprite
│  │  └─ Render Transform: Rotation = Velocity Bearing
│  └─ [Text Block] "VelocityText" - "85 m/s"
│
├─ [Spacer] - 20px
│
└─ [Uniform Grid Panel] - Command Buttons (2x3)
   ├─ [Button] "AlignToButton" (0,0)
   │  └─ [Text Block] "Align To"
   ├─ [Button] "OrbitButton" (0,1)
   │  └─ [Text Block] "Orbit"
   ├─ [Button] "WarpToButton" (0,2)
   │  └─ [Text Block] "Warp To"
   ├─ [Button] "ApproachButton" (1,0)
   │  └─ [Text Block] "Approach"
   ├─ [Button] "KeepAtRangeButton" (1,1)
   │  └─ [Text Block] "Keep At Range"
   └─ [Button] "StopButton" (1,2)
      └─ [Text Block] "STOP" (Red)
```

### Blueprint Setup (WBP_Navigation)

**Event Graph**:
```
Event Construct
  ↓
Get Player Pawn
  ↓
BindToShip(Player Pawn)
  ↓
Bind Button Click Events (done in C++)
  ↓
Update Button States


SetNavigationTarget (Target)
  ↓
Store Target Reference
  ↓
Update Button States
  │ If Target == null
  │   → Disable all buttons except Stop
  │ Else
  │   → Enable all buttons


OnNavigationCommandExecuted (Command, Target)
  ↓
Play Sound based on Command Type
  ↓
Show Visual Feedback (highlight button briefly)
  ↓
Print Debug "Executing [CommandName] on [TargetName]"
```

**Updating Velocity Arrow**:
```
Function: UpdateVelocityArrow
  ↓
Get Ship Velocity
  ↓
Calculate Magnitude
  │ If < 1 m/s → Hide Arrow
  │ Else → Show Arrow
  ↓
Calculate Bearing (Atan2)
  ↓
Set Velocity Arrow Render Transform
  │ Rotation = Bearing
  ↓
Set Velocity Text
  │ Text = FormatSpeed(Magnitude)
```

### Button Style Customization

Create button styles in UMG:
- **Normal**: Dark gray, subtle border
- **Hovered**: Light blue glow
- **Pressed**: Bright blue, scale 0.95
- **Disabled**: Dark gray, 50% opacity

For Stop button:
- **Normal**: Red tint
- **Hovered**: Bright red
- **Pressed**: Dark red

## Complete Integration Example

### PlayerController Blueprint

```
Event BeginPlay
  ↓
Create Widget (WBP_EchoesMainHUD)
  ↓
Add to Viewport
  ↓
Store HUD Reference
  ↓
Initialize HUD
  │ SetGameState(InSpace)
  │  ↓
  │ OnEnterSpace Event
  │  │ Get Player Ship
  │  │  ↓
  │  │ Bind All Widgets:
  │  │  ├─ ShipStatus → BindToShip
  │  │  ├─ Navigation → BindToShip
  │  │  ├─ TargetPanel → BindToTargetingComponent
  │  │  └─ Overview → PopulateOverview
```

### Docking/Undocking Events

```
Event OnDock
  ↓
HUD → SetGameState(InHangar)
  ↓
Clear Overview
Clear Target Panel


Event OnUndock
  ↓
HUD → SetGameState(InSpace)
  ↓
Reinitialize Space HUD
  ↓
Populate Overview
```

## Data Binding Examples

### Binding Ship Health to Ship Status Widget

**Option 1: Manual Binding (C++)**
```cpp
// In ship pawn
void AShipPawn::UpdateHealth()
{
    if (UShipStatusWidget* StatusWidget = GetHUDShipStatusWidget())
    {
        StatusWidget->ClientOnly_UpdateShield(GetShieldPercentage(), 
                                               ShieldCurrent, ShieldMax);
        // ... same for Armor, Hull, Capacitor
    }
}
```

**Option 2: Interface Binding (C++)**
```cpp
// Ship implements IShipStateInterface
FCommon_ShipDataStruct AShipPawn::GetShipData_Implementation() const
{
    FCommon_ShipDataStruct Data;
    Data.ShieldCurrent = ShieldCurrent;
    Data.ShieldMax = ShieldMax;
    // ... fill all fields
    return Data;
}

// Widget queries automatically
void UShipStatusWidget::HandlePeriodicUpdate()
{
    ClientOnly_RefreshAllDisplays(); // Calls GetShipData()
}
```

**Option 3: Event Binding (Blueprint)**
```
In Ship Blueprint:
  OnHealthChanged Event
    ↓
  Get HUD Widget
    ↓
  Cast to ShipStatusWidget
    ↓
  ClientOnly_UpdateShield/Armor/Hull
```

### Binding Targets to Target Panel

**Automatic (Recommended)**:
```cpp
// In HUD initialization
TargetPanelWidget->BindToTargetingComponent(TargetingComp);
// Now updates automatically via delegates
```

**Manual**:
```
In TargetingComponent:
  OnLockCompleted Event
    ↓
  Get HUD
    ↓
  Get Target Panel Widget
    ↓
  ClientOnly_AddTarget(Target, Data)
```

## Performance Tips

### Invalidation Boxes
Wrap static elements in Invalidation Boxes:
```
[Invalidation Box]
└─ [Vertical Box] - Button Container
   └─ All navigation buttons
```
Only invalidates when buttons change, not every frame.

### Material Instance Pooling
For radial bars, create Material Instance Constants in Blueprint:
```
Event PreConstruct
  ↓
Create Material Instance Dynamic for each bar
  │ ShieldBarMI = CreateDynamicMaterialInstance(M_RadialBar)
  │ ...
  ↓
Store in variables
  ↓
Reuse for all updates (don't recreate)
```

### ListView Settings
In Overview widget ListView properties:
- **Entry Widget Pool**: Set to 20-30 (visible + buffer)
- **Virtualization**: Enabled (default)
- **Scroll Bar Visibility**: Auto or Hidden

## Styling Guide

### Color Palette
- **Shield**: Blue `(0.0, 0.5, 1.0)`
- **Armor**: Yellow/Orange `(1.0, 0.7, 0.0)`
- **Hull**: Red `(1.0, 0.0, 0.0)`
- **Capacitor**: Cyan `(0.0, 0.7, 1.0)`
- **Friendly**: Green `(0.0, 1.0, 0.0)`
- **Hostile**: Red `(1.0, 0.0, 0.0)`
- **Neutral**: Gray `(0.7, 0.7, 0.7)`

### Typography
- **Headers**: Bold, 18-24pt
- **Primary Values**: Bold, 36-48pt (speed, distances)
- **Secondary Values**: Regular, 12-14pt
- **Labels**: Regular, 10-12pt

### Layout
- **Margins**: 10-20px between major sections
- **Padding**: 5-10px within containers
- **Button Size**: Minimum 100x40px for click targets
- **Icon Size**: 32x32px or 64x64px

## Troubleshooting

### Widgets Not Updating
1. Check binding: `BindToShip()` or `BindToTargetingComponent()` called?
2. Verify interface implementation: Does ship implement `IShipStateInterface`?
3. Check timer: Is `UpdateInterval` > 0?
4. Debug logs: Add print statements in update functions

### Radial Bars Not Showing
1. Verify material assignment: Check Image widgets have materials
2. Check material parameters: Are they named correctly?
3. Verify Progress range: Must be 0.0 to 1.0
4. Check InnerRadius < OuterRadius

### Buttons Not Working
1. Verify binding: Are `OnClicked` events bound?
2. Check enabled state: Is `SetIsEnabled(true)` called?
3. Verify navigation target: Required for most commands
4. Check click event propagation: Not blocked by overlays?

### ListView Performance Issues
1. Reduce entry count: Use filtering/pagination
2. Simplify row widgets: Less complex layouts
3. Check update frequency: 1 Hz recommended
4. Use ListView pooling: Don't create/destroy entries

## Conclusion

This guide provides complete UMG hierarchies and Blueprint integration for all Space HUD modules. Follow these structures for consistent, performant UI implementation. All widgets support both C++ and Blueprint workflows for maximum flexibility.

For additional examples and advanced customization, refer to the SPACE_HUD_ARCHITECTURE.md document.
