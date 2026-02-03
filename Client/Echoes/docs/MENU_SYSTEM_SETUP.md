# Menu System Integration Guide

## Overview

This guide explains the complete authorization flow and menu system for Echoes MMO, including the centralized widget management through `AEchoesMenuPlayerController`.

## Architecture

### Authorization Chain

The menu system implements a complete authorization flow:

```
Preload (token validation)
    ↓
Login (if no valid token)
    ↓
Character Select
    ↓
ConnectToWorld (via AuthSubsystem)
    ↓
ClientTravel to game server
```

### Key Components

1. **AEchoesMenuGameMode** - Base game mode for all menu maps
2. **AEchoesMenuPlayerController** - Centralized widget controller
3. **UEchoesPreloadWidget** - Initial validation screen
4. **UEchoesLoginWidget** - Authentication screen
5. **UEchoesCharacterSelectWidget** - Character selection screen

## Class Details

### AEchoesMenuGameMode

**Purpose**: Base game mode for all menu maps (EntryMap, CharacterSelectMap)

**Key Features**:
- No pawn spawning (`DefaultPawnClass = nullptr`)
- Prevents spawn attempts (`ShouldSpawnAtStartSpot` returns false)
- Uses `AEchoesMenuPlayerController` for UI management

**C++ Location**: `Source/Echoes/EchoesMenuGameMode.h/cpp`

### AEchoesMenuPlayerController

**Purpose**: Centralized menu controller for authorization flow

**Key Features**:
- `ShowLoginScreen()` - Display login widget
- `ShowCharacterSelect()` - Display character selection widget
- `ChangeWidget()` - Private method for widget transitions
- Handles `bShowMouseCursor = true` and `FInputModeUIOnly`
- Only operates on local player controllers

**Authorization Flow**:
1. BeginPlay() starts with Preload widget
2. Preload validates saved token
3. On success → Character Select
4. On failure → Login
5. After login → Character Select
6. After character selection → ConnectToWorld

**C++ Location**: `Source/Echoes/EchoesMenuPlayerController.h/cpp`

### Widget Flow Details

#### 1. Preload Widget
- Checks API connectivity
- Validates saved JWT token
- Broadcasts `OnPreloadComplete` with next state

#### 2. Login Widget
- User enters credentials
- Calls `AuthSubsystem->Auth_Login()`
- On success, broadcasts `OnLoginSuccessDelegate`
- Controller automatically transitions to Character Select

#### 3. Character Select Widget
- Displays available characters
- Allows character creation
- Calls `AuthSubsystem->ConnectToWorld(CharacterId)`
- AuthSubsystem handles ClientTravel to game server

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
5. In the Details panel, configure three widget classes:
   - `Preload Widget Class` → Set to `WBP_Preload`
   - `Login Widget Class` → Set to `WBP_Login`
   - `Character Select Widget Class` → Set to `WBP_CharacterSelect`

### Step 3: Configure Entry Map (Menu Map)

1. Open your `EntryMap` or menu map
2. Go to World Settings (Window → World Settings)
3. Under "Game Mode" section:
   - Check "GameMode Override"
   - Set it to `BP_EchoesMenuGameMode`
4. Save the map

### Step 4: Verify Widget Integration

The widgets should already be configured to work with the new system:

**Preload Widget**:
- Automatically starts validation on creation
- Broadcasts `OnPreloadComplete` when done
- Controller handles the transition

**Login Widget**:
- Calls `AuthSubsystem->Auth_Login()`
- Broadcasts `OnLoginSuccessDelegate` on success
- Controller automatically shows Character Select

**Character Select Widget**:
- Should call `AuthSubsystem->ConnectToWorld(CharacterId)` on character selection
- Remove any `OpenLevel` or `LaunchCharacter` calls that use `OpenLevel`

## How It Works

### Complete Authorization Flow:

1. **Player opens EntryMap**
   - `BP_EchoesMenuGameMode` is used
   - No pawn is spawned

2. **BeginPlay() on BP_EchoesMenuPlayerController**
   - Creates `WBP_Preload` widget
   - Adds it to viewport
   - Sets input mode to UI-only
   - Shows mouse cursor
   - Binds to `OnPreloadComplete` event

3. **Preload validation**
   - Checks API connectivity (GET /api/system/status)
   - Verifies client version
   - Loads saved JWT token
   - Validates token (POST /api/auth/validate-token)
   
4. **Transition based on preload result**:
   
   **If token is valid**:
   - Controller calls `ShowCharacterSelect()`
   - User goes directly to character selection
   
   **If no token or token invalid**:
   - Controller calls `ShowLoginScreen()`
   - User must authenticate first

5. **Login flow (if needed)**:
   - User enters credentials
   - Widget calls `AuthSubsystem->Auth_Login()`
   - On success, widget broadcasts `OnLoginSuccessDelegate`
   - Controller automatically calls `ShowCharacterSelect()`

6. **Character selection**:
   - User selects or creates a character
   - Widget calls `AuthSubsystem->ConnectToWorld(CharacterId)`

7. **ConnectToWorld() process**:
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

### Widget Transition Details:

**ChangeWidget() method**:
```cpp
void AEchoesMenuPlayerController::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    // Remove current widget if it exists
    if (CurrentWidget)
    {
        CurrentWidget->RemoveFromParent();
        CurrentWidget = nullptr;
    }
    
    // Create and display new widget
    CurrentWidget = CreateWidget<UUserWidget>(this, NewWidgetClass);
    CurrentWidget->AddToViewport();
    
    // Configure input mode: UI only, mouse cursor visible
    FInputModeUIOnly InputMode;
    InputMode.SetWidgetToFocus(CurrentWidget->TakeWidget());
    SetInputMode(InputMode);
    bShowMouseCursor = true;
}
```

### Game Server Flow:

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
- Verify widget classes are set in `BP_EchoesMenuPlayerController`:
  - `PreloadWidgetClass` → `WBP_Preload`
  - `LoginWidgetClass` → `WBP_Login`
  - `CharacterSelectWidgetClass` → `WBP_CharacterSelect`
- Check that all widget blueprints exist and are valid
- Look for errors in Output Log mentioning "LogEchoesMenu"

### Preload screen stuck:
- Check API server is running and accessible
- Verify API URL in Config/DefaultGame.ini under [Network] section
- Review console for "Preload Fatal:" errors
- Check network connectivity to backend server

### Login screen not showing after preload:
- Verify `OnPreloadComplete` delegate is properly bound
- Check `LoginWidgetClass` is set in Blueprint
- Review logs for "Preload complete, transitioning to next state" message

### Character select not showing after login:
- Verify login was successful (check logs for "Login successful")
- Check `CharacterSelectWidgetClass` is set in Blueprint
- Ensure `OnLoginSuccessDelegate` lambda is calling `ShowCharacterSelect()`

### "None" error on GetPlayerController:
- This should be fixed by the new controller architecture
- Controller creates widgets only when fully initialized
- Verify you're using `BP_EchoesMenuGameMode` in World Settings

### Mouse not visible:
- Controller automatically sets `bShowMouseCursor = true` in `ChangeWidget()`
- Input mode is set to UI-only for each widget
- If still not visible, check for conflicting input mode settings

### Still opening map locally:
- Verify widget is calling `ConnectToWorld()` not `OpenLevel()`
- Check AuthSubsystem is valid before calling
- Remove any remaining `OpenLevel()` or `ServerTravel()` calls

### Connection fails:
- Verify backend API is running on correct port
- Check JWT token is valid (not expired)
- Ensure character exists in database
- Review backend logs for /character/{id}/connect-info endpoint
- Check firewall allows connection to game server port

### Widget transitions not working:
- Ensure `ChangeWidget()` is called with valid widget class
- Check CurrentWidget is properly removed before creating new one
- Verify all widget classes derive from UUserWidget
- Review LogEchoesMenu logs for transition messages

## Testing

### Test Authorization Flow Locally:

1. **Start backend API server**
   ```bash
   cd EchoesBackend_v1
   dotnet run
   ```

2. **Launch Unreal Editor**
   - Open Echoes.uproject

3. **Test Preload → Login → Character Select**:
   
   **Test Case 1: No saved token (first time)**
   - PIE (Play In Editor) with EntryMap
   - Verify Preload screen appears
   - Check console: "No saved credentials found"
   - Verify Login screen appears automatically
   - Enter credentials and login
   - Verify Character Select screen appears

   **Test Case 2: Valid saved token**
   - Login successfully (to save token)
   - Close PIE
   - PIE again with EntryMap
   - Verify Preload screen appears
   - Check console: "Token validated successfully"
   - Verify Character Select appears directly (skipping Login)

   **Test Case 3: Invalid/expired token**
   - Manually edit saved token in AppData
   - PIE with EntryMap
   - Verify Preload screen appears
   - Check console: "Token invalid or expired"
   - Verify Login screen appears

4. **Verify each screen**:
   - **Preload**: Loading bar, status messages
   - **Login**: Email/password fields, Remember Me checkbox
   - **Character Select**: Character list, create/delete buttons
   
5. **Verify transitions**:
   - Check LogEchoesMenu logs for transition messages
   - Verify mouse is visible on all screens
   - Confirm input mode is UI-only

### Test Character Selection:

1. On Character Select screen
2. Select a character
3. Click "Enter Game" or "Play"
4. Verify console shows: "Traveling to: ..."
5. Verify client attempts to connect to game server

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
