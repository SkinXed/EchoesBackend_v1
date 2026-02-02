# Menu System Integration Guide

## Overview

This guide explains how to set up the new menu system classes for proper character selection and server travel in Echoes MMO.

## Architecture Changes

### Problem Solved
Previously, the character select widget used `UGameplayStatics::OpenLevel()` which opened maps locally. For an MMO, we need `ClientTravel()` to connect to dedicated servers via network.

### Solution
Two new classes separate menu logic from game logic:

1. **EchoesMenuGameMode** - Game mode for character selection menu
2. **EchoesMenuPlayerController** - Controller that manages UI and input

## Class Details

### AEchoesMenuGameMode

**Purpose**: Manages character selection menu map

**Key Features**:
- No pawn spawning (`DefaultPawnClass = nullptr`)
- Prevents spawn attempts (`ShouldSpawnAtStartSpot` returns false)
- Uses `AEchoesMenuPlayerController` for UI management

**C++ Location**: `Source/Echoes/EchoesMenuGameMode.h/cpp`

### AEchoesMenuPlayerController

**Purpose**: Handles UI creation and input management for menu

**Key Features**:
- Creates character select widget on `BeginPlay()`
- Only operates on local controller (prevents server/remote creation)
- Sets input mode to UI-only with visible mouse cursor
- Properly configures widget focus

**C++ Location**: `Source/Echoes/EchoesMenuPlayerController.h/cpp`

## Blueprint Setup Instructions

### Step 1: Create Menu Game Mode Blueprint

1. In Content Browser, navigate to your GameModes folder
2. Right-click → Blueprint Class → Search for "EchoesMenuGameMode"
3. Name it `BP_EchoesMenuGameMode`
4. Open the Blueprint and verify:
   - `PlayerControllerClass` should auto-set to `EchoesMenuPlayerController`
   - `DefaultPawnClass` should be None

### Step 2: Create Menu Player Controller Blueprint

1. In Content Browser, navigate to your Controllers folder
2. Right-click → Blueprint Class → Search for "EchoesMenuPlayerController"
3. Name it `BP_EchoesMenuPlayerController`
4. Open the Blueprint
5. In the Details panel, find "Character Select Widget Class"
6. Set it to your existing `WBP_CharacterSelect` widget

### Step 3: Configure Character Select Map

1. Open your `CharacterSelectMap` (or menu map)
2. Go to World Settings (Window → World Settings)
3. Under "Game Mode" section:
   - Check "GameMode Override"
   - Set it to `BP_EchoesMenuGameMode`
4. Save the map

### Step 4: Modify Character Select Widget Blueprint

The widget needs to use `ConnectToWorld()` instead of `LaunchCharacter()`:

**Before** (Old approach):
```
On Button Click → LaunchCharacter(CharacterId)
  ↓
UGameplayStatics::OpenLevel(GalaxyMap)  // Local only!
```

**After** (New approach):
```
On Button Click → AuthSubsystem->ConnectToWorld(CharacterId)
  ↓
Gets server IP:Port from API
  ↓
PlayerController->ClientTravel(IP:Port)  // Network travel!
```

#### Implementation in Blueprint:

1. Open `WBP_CharacterSelect` (your character selection widget)
2. Find the "Enter Game" or "Play" button's OnClicked event
3. Replace the call to `LaunchCharacter` with:
   ```
   Get Game Instance → Get Subsystem (EchoesAuthSubsystem) → ConnectToWorld (CharacterId)
   ```
4. Remove any references to `GalaxyLevelName` or `OpenLevel`

#### If you have C++ widget code:

In `EchoesCharacterSelectWidget.cpp`, modify the character launch function:

```cpp
// OLD CODE (remove this):
void UEchoesCharacterSelectWidget::LaunchCharacter(FGuid CharacterId)
{
    UGameplayStatics::OpenLevel(this, GalaxyLevelName, true, Options);
}

// NEW CODE (use this):
void UEchoesCharacterSelectWidget::LaunchCharacter(FGuid CharacterId)
{
    if (AuthSubsystem)
    {
        // This will get server connection info and perform ClientTravel
        AuthSubsystem->ConnectToWorld(CharacterId);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AuthSubsystem not available"));
    }
}
```

## How It Works

### Menu Flow:

1. **Player opens CharacterSelectMap**
   - `BP_EchoesMenuGameMode` is used
   - No pawn is spawned

2. **BeginPlay() on BP_EchoesMenuPlayerController**
   - Creates `WBP_CharacterSelect` widget
   - Adds it to viewport
   - Sets input mode to UI-only
   - Shows mouse cursor

3. **Player selects character and clicks "Enter"**
   - Widget calls `AuthSubsystem->ConnectToWorld(CharacterId)`

4. **ConnectToWorld() process**:
   ```
   GET /character/{id}/connect-info
     ↓
   Response: { "serverIP": "127.0.0.1", "serverPort": 7777 }
     ↓
   PlayerController->ClientTravel("127.0.0.1:7777?Token=...&CharacterId=...")
     ↓
   Client connects to dedicated server
     ↓
   EchoesServerGameMode handles login and spawns player
   ```

### Game Flow:

1. **Client connects to dedicated server**
   - URL parameters include Token and CharacterId
   - `EchoesServerGameMode` is used

2. **Server validates token**
   - Calls backend API to verify session
   - Loads character data

3. **Server spawns player**
   - Generates world from config
   - Spawns player pawn/ship
   - Initializes inventory and stats

## Troubleshooting

### Widget not appearing:
- Verify `CharacterSelectWidgetClass` is set in `BP_EchoesMenuPlayerController`
- Check that `WBP_CharacterSelect` exists and is valid
- Look for errors in Output Log mentioning "EchoesMenuPlayerController"

### "None" error on GetPlayerController:
- This is fixed by the new controller creating the widget
- Old approach tried to create widget before controller was ready

### Mouse not visible:
- Controller automatically sets `bShowMouseCursor = true`
- Input mode is set to UI-only

### Still opening map locally:
- Verify widget is calling `ConnectToWorld()` not `OpenLevel()`
- Check AuthSubsystem is valid before calling

### Connection fails:
- Verify backend API is running on correct port
- Check JWT token is valid
- Ensure character exists in database
- Review backend logs for /connect-info endpoint

## Testing

### Test Locally:

1. Start backend API server
2. Launch Unreal Editor
3. PIE (Play In Editor) with CharacterSelectMap
4. Verify:
   - Widget appears automatically
   - Mouse is visible
   - Character list loads
   - Selecting character calls ConnectToWorld
   - Console shows "Traveling to: ..." message

### Test with Dedicated Server:

1. Package the project
2. Start backend API server
3. Start dedicated server: `YourGame.exe -server GalaxyMap` (or your game map)
4. Launch client: `YourGame.exe`
5. Login and select character
6. Client should travel to dedicated server

**Note**: The dedicated server should start with a gameplay map (like GalaxyMap), not CharacterSelectMap. The menu is for client-side only.

## Related Files

- `Source/Echoes/EchoesMenuGameMode.h/cpp` - Menu game mode
- `Source/Echoes/EchoesMenuPlayerController.h/cpp` - Menu controller
- `Source/Echoes/EchoesServerGameMode.h/cpp` - Game server mode
- `Source/Echoes/Core/Common/Networking/EchoesAuthSubsystem.h/cpp` - Auth and ConnectToWorld
- `Source/Echoes/UI/Widgets/EchoesCharacterSelectWidget.h/cpp` - Character select UI

## Benefits

✅ **Proper Client-Server Architecture**: Uses ClientTravel instead of local OpenLevel
✅ **Clean Separation**: Menu logic separate from game logic
✅ **MMO-Ready**: Connects to dynamic server instances
✅ **Eliminates "None" Errors**: Widget created at correct time in controller lifecycle
✅ **Scalable**: Backend can assign players to different server instances
✅ **Blueprint Friendly**: Easy to configure without C++ changes
