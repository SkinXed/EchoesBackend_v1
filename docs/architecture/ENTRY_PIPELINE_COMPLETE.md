# Final Entry Pipeline Integration - Complete Implementation Guide

## Overview
This document describes the complete implementation of the 5-node entry pipeline system, enabling seamless transition from client startup to appearing in the game world.

## Architecture Overview

```
Player Launch → W_Preload (Cold Start) → W_Login (Auth) → W_CharacterSelect (World Entry)
                    ↓                          ↓                      ↓
              Check Token              Get JWT Token          Connect to Server
              Validate Token           Save if Remember       ClientTravel
                    ↓                          ↓                      ↓
           Character Select          Character Select         GameMode::PostLogin
                                                                      ↓
                                                            Extract Token & Character
                                                                      ↓
                                                            Query Character Location
                                                                      ↓
                                                     IsDocked?  ┌─────┴─────┐
                                                               YES          NO
                                                                │            │
                                                          Station Spawn  Space Spawn
                                                                │            │
                                                                └─────┬─────┘
                                                                      ↓
                                                           OnEntryFlowComplete
                                                                      ↓
                                                              Remove UI, Game Ready
```

## 1. Persistence: LocalPlayerSettings

### Implementation
**File:** `Client/Echoes/Source/Echoes/Core/Common/Save/EchoesLocalPlayerSettings.h/cpp`

**Class:** `UEchoesLocalPlayerSettings : public USaveGame`

**Saved Data:**
```cpp
FString SavedAuthToken;         // JWT token
FGuid SavedCharacterId;         // Last selected character
FGuid SavedAccountId;           // Account ID
FDateTime TokenSavedAt;         // When saved
FDateTime TokenExpiresAt;       // Expiration time
bool bRememberMe;               // Remember me flag
```

**Key Methods:**
- `LoadSettings()` - Load from disk or create new
- `SaveSettings(Settings)` - Save to disk (slot: "EchoesLocalPlayerSettings")
- `IsTokenValid()` - Check if token exists and not expired
- `Clear()` - Clear all saved data

### Integration Points

**AuthSubsystem:**
```cpp
void SaveAuthToken(bool bRememberMe);  // Save token to disk
bool LoadAuthToken();                  // Load token from disk
void ClearSavedToken();                // Clear saved token
```

**W_Preload:**
```cpp
FString GetSavedToken() const
{
    UEchoesLocalPlayerSettings* Settings = UEchoesLocalPlayerSettings::LoadSettings();
    if (Settings && Settings->IsTokenValid())
        return Settings->SavedAuthToken;
    return FString();
}
```

**W_Login:**
```cpp
void OnLoginSuccess(const FAuthResponse& AuthResponse)
{
    if (RememberMeCheckbox && RememberMeCheckbox->IsChecked())
        AuthSubsystem->SaveAuthToken(true);
}
```

## 2. UI Plumbing: Blueprint Integration

### Delegates (Dynamic Multicast)

**Character Operations:**
```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterCreated, const FCharacterData&, CharacterData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterCreationFailed, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConnectInfoReceived, const FString&, ServerIP, int32, ServerPort);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectInfoFailed, const FString&, ErrorMessage);
```

**Usage in Blueprints:**
```
AuthSubsystem->OnCharacterCreated.AddDynamic(this, &UMyWidget::OnCharacterCreatedHandler);
AuthSubsystem->CreateCharacter("MyCharacter", 1);  // Caldari
```

### Blueprint-Callable Methods

**Authentication:**
- `Auth_Login(Request, OnSuccess, OnFailure)` - ✅ Already BlueprintCallable
- `Auth_Register(Username, Email, Password, OnSuccess, OnFailure)` - ✅ Already BlueprintCallable
- `Auth_GetToken()` - ✅ Already BlueprintPure
- `Auth_GetCharacters()` - ✅ Already BlueprintPure
- `Auth_Logout()` - ✅ Already BlueprintCallable

**Token Persistence:**
- `SaveAuthToken(bRememberMe)` - ✅ NEW: BlueprintCallable
- `LoadAuthToken()` - ✅ NEW: BlueprintCallable
- `ClearSavedToken()` - ✅ NEW: BlueprintCallable

**Character Operations:**
- `CreateCharacter(CharacterName, RaceId)` - ✅ NEW: BlueprintCallable
- `FetchCharacterList()` - ✅ NEW: BlueprintCallable
- `ConnectToWorld(CharacterId)` - ✅ NEW: BlueprintCallable

## 3. The "Jump": ClientTravel Implementation

### ConnectToWorld Method

**Location:** `EchoesAuthSubsystem::ConnectToWorld(CharacterId)`

**Flow:**
1. Validate authentication (JWT token exists)
2. HTTP GET to `/api/character/{id}/connect-info`
3. Parse response:
   ```json
   {
     "serverIP": "127.0.0.1",
     "serverPort": 7777,
     "systemId": "guid",
     "isDocked": true,
     "stationId": "guid"
   }
   ```
4. Build connection URL:
   ```cpp
   FString ConnectURL = FString::Printf(
       TEXT("%s:%d?Token=%s&CharacterId=%s"),
       *ServerIP, ServerPort, *JWTToken, *CharacterId.ToString()
   );
   ```
5. Execute ClientTravel:
   ```cpp
   PC->ClientTravel(ConnectURL, TRAVEL_Absolute);
   ```

### Character Select Integration

**W_CharacterSelect "Enter World" Button:**
```cpp
void OnEnterWorldClicked()
{
    if (AuthSubsystem && SelectedCharacter)
    {
        // This will fetch connect-info and automatically travel
        AuthSubsystem->ConnectToWorld(SelectedCharacter->CharacterId);
    }
}
```

**Events:**
- `OnConnectInfoReceived(ServerIP, ServerPort)` - Fired before travel
- `OnConnectInfoFailed(ErrorMessage)` - Fired on error

## 4. Server-Side Spawn Logic

### GameMode::PostLogin

**File:** `EchoesServerGameMode::PostLogin()`

**Implementation:**
```cpp
void AEchoesServerGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
    
    if (!HasAuthority()) return;
    
    // Extract login options
    FString Options = NewPlayer->PlayerState->SavedNetworkAddress;
    FString Token;
    FGuid CharacterId;
    
    if (ExtractLoginOptions(Options, Token, CharacterId))
    {
        // Token and CharacterId extracted successfully
        SpawnPlayerAtLocation(NewPlayer);
    }
}
```

### ExtractLoginOptions

**Parses URL:** `?Token=xxx&CharacterId=yyy`

**Returns:**
- `OutToken` - JWT token string
- `OutCharacterId` - Character GUID

### SpawnPlayerAtLocation

**Current Implementation:**
```cpp
void SpawnPlayerAtLocation(APlayerController* PC)
{
    // 1. Extract character info from connection
    FString Token;
    FGuid CharacterId;
    ExtractLoginOptions(Options, Token, CharacterId);
    
    // 2. TODO: Query backend for location
    //    GET /api/character/{id}/location
    //    Response: { isDocked, stationId, positionX/Y/Z }
    
    // 3. Spawn based on state
    //    if (isDocked)
    //        SpawnPlayerAtStation(PC, StationId);
    //    else
    //        SpawnPlayerInSpace(PC, Position, Rotation);
    
    // 4. For now: spawn at default location
    RestartPlayer(PC);
    
    // 5. Broadcast completion
    OnEntryFlowComplete.Broadcast();
}
```

### SpawnPlayerAtStation

**TODO Implementation:**
```cpp
void SpawnPlayerAtStation(APlayerController* PC, const FGuid& StationId)
{
    // 1. Find AStationActor by StationId
    AStationActor* Station = FindStationById(StationId);
    
    // 2. Dock player
    Station->DockPlayer(PC);
    
    // 3. Open station menu
    // PC->ShowWidget(W_StationMenu);
    
    // 4. Signal complete
    OnEntryFlowComplete.Broadcast();
}
```

### SpawnPlayerInSpace

**TODO Implementation:**
```cpp
void SpawnPlayerInSpace(APlayerController* PC, const FVector& Position, const FRotator& Rotation)
{
    // 1. Get player's ship from database
    // 2. Spawn ship actor at position
    // 3. Possess ship
    // 4. Sync inventory component
    // 5. Set velocity and orientation
    
    OnEntryFlowComplete.Broadcast();
}
```

## 5. Flow Completion: OnEntryFlowComplete

### Delegate Declaration

**File:** `EchoesServerGameMode.h`

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEntryFlowComplete);

UPROPERTY(BlueprintAssignable, Category = "Echoes|Entry")
FOnEntryFlowComplete OnEntryFlowComplete;
```

### When Broadcasted

**Triggered after:**
- Pawn is spawned
- Inventory component synced (TODO)
- Player ready for gameplay

**Example:**
```cpp
RestartPlayer(PC);
if (PC->GetPawn())
{
    // TODO: Sync inventory
    OnEntryFlowComplete.Broadcast();
}
```

### HUD Integration

**TODO Implementation:**

**Blueprint/C++ Logic:**
```cpp
void AMyHUD::BeginPlay()
{
    // Subscribe to event
    AEchoesServerGameMode* GM = GetWorld()->GetAuthGameMode<AEchoesServerGameMode>();
    if (GM)
    {
        GM->OnEntryFlowComplete.AddDynamic(this, &AMyHUD::OnEntryComplete);
    }
}

void AMyHUD::OnEntryComplete()
{
    // Remove entry widgets
    if (W_Preload) W_Preload->RemoveFromParent();
    if (W_Login) W_Login->RemoveFromParent();
    if (W_CharacterSelect) W_CharacterSelect->RemoveFromParent();
    
    // Switch to game input mode
    APlayerController* PC = GetOwningPlayerController();
    PC->SetShowMouseCursor(false);
    PC->SetInputMode(FInputModeGameOnly());
    
    // Show game HUD
    // ShowGameplayWidgets();
}
```

## Complete Entry Flow Example

### 1. Cold Start (W_Preload)
```
Player launches game
W_Preload::StartPreload()
→ Check /api/system/status
→ Load UEchoesLocalPlayerSettings
→ If valid token exists:
  → POST /api/auth/validate-token
  → If valid: OnPreloadComplete(CharacterSelect)
  → If invalid: OnPreloadComplete(Login)
→ If no token:
  → OnPreloadComplete(Login)
```

### 2. Login (W_Login) [If needed]
```
Player enters credentials
Click Login button
→ AuthSubsystem->Auth_Login(Request)
→ Backend returns JWT + character list
→ If RememberMe checked:
  → AuthSubsystem->SaveAuthToken(true)
  → Saves to LocalPlayerSettings
→ OnLoginSuccess event
→ Show W_CharacterSelect
```

### 3. Character Select (W_CharacterSelect)
```
Display character list from AuthSubsystem
Player selects character (or creates new)

[New Character Flow]
→ Select race from dropdown
→ Enter character name
→ AuthSubsystem->CreateCharacter(Name, RaceId)
→ Backend creates character with starting station
→ OnCharacterCreated event
→ Refresh character list

[Enter World Flow]
→ Click "Enter World" button
→ AuthSubsystem->ConnectToWorld(CharacterId)
→ GET /api/character/{id}/connect-info
→ Receive: ServerIP, Port, SystemId, IsDocked
→ Build URL: "127.0.0.1:7777?Token=xxx&CharacterId=yyy"
→ PC->ClientTravel(URL, TRAVEL_Absolute)
```

### 4. Server Spawn (GameMode::PostLogin)
```
Player connects to game server
GameMode::PostLogin(PC)
→ ExtractLoginOptions(Options, Token, CharacterId)
→ SpawnPlayerAtLocation(PC)
  → Query backend (TODO): GET /api/character/{id}/location
  → If isDocked:
    → SpawnPlayerAtStation(PC, StationId)
    → Find AStationActor by ID (TODO)
    → Station->DockPlayer(PC) (TODO)
    → Open W_StationMenu (TODO)
  → If in space:
    → SpawnPlayerInSpace(PC, Position, Rotation)
    → Spawn ship actor (TODO)
    → Sync inventory (TODO)
→ OnEntryFlowComplete.Broadcast()
```

### 5. Game Ready (HUD)
```
HUD receives OnEntryFlowComplete event
→ Remove all entry widgets:
  → W_Preload->RemoveFromParent()
  → W_Login->RemoveFromParent()
  → W_CharacterSelect->RemoveFromParent()
→ Switch input mode:
  → SetShowMouseCursor(false)
  → SetInputMode(FInputModeGameOnly())
→ Show gameplay HUD
→ Player can now play
```

## API Endpoints Used

### Client → Backend

| Endpoint | Method | Purpose | When Called |
|----------|--------|---------|-------------|
| `/api/system/status` | GET | Health check | W_Preload cold start |
| `/api/auth/validate-token` | POST | Validate saved JWT | W_Preload with saved token |
| `/api/auth/login` | POST | Get JWT token | W_Login on submit |
| `/api/character/list` | GET | Get account's characters | After login success |
| `/api/character` | POST | Create new character | W_CharacterSelect create |
| `/api/character/{id}/connect-info` | GET | Get server connection info | W_CharacterSelect enter world |
| `/api/character/{id}/location` | GET | Get character spawn location | GameMode::PostLogin (TODO) |

## Configuration

### appsettings.json (Backend)
```json
{
  "Jwt": {
    "Secret": "your-secret-key",
    "Issuer": "EchoesAPI",
    "Audience": "EchoesClient",
    "ExpirationHours": 24
  }
}
```

### DefaultGame.ini (UE5)
```ini
[/Script/Echoes.EchoesAuthSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=UE5-Server-Secret-Change-Me-In-Production
```

## Testing Checklist

### Persistence
- [ ] Launch game, login with "Remember Me", close game
- [ ] Launch game again, should skip login (cold start success)
- [ ] Wait for token expiration, should go to login
- [ ] Login without "Remember Me", close game
- [ ] Launch game, should go to login (no saved token)

### Character Operations
- [ ] Create character with each race (Caldari, Gallente, Amarr, Minmatar)
- [ ] Verify starting station assigned based on race
- [ ] List characters shows all created characters
- [ ] Select character and enter world

### Connection
- [ ] "Enter World" fetches connect-info
- [ ] ClientTravel executes with correct URL format
- [ ] Server receives Token and CharacterId in connection options
- [ ] Server extracts data correctly

### Spawn
- [ ] Server spawns player pawn
- [ ] OnEntryFlowComplete broadcasts
- [ ] HUD removes entry widgets (when implemented)
- [ ] Input mode switches to game only (when implemented)

## Known Limitations

1. **GameMode HTTP Call:** Server doesn't query character location from backend yet
2. **Station Spawn:** SpawnPlayerAtStation doesn't find StationActor or call DockPlayer
3. **Space Spawn:** SpawnPlayerInSpace doesn't spawn ship or sync inventory
4. **HUD Integration:** No HUD listens to OnEntryFlowComplete yet
5. **Inventory Sync:** No inventory synchronization after spawn

## Next Steps

1. **Implement HTTP in GameMode:**
   - Add HTTP module to GameMode
   - Query `/api/character/{id}/location` in SpawnPlayerAtLocation
   - Parse response and call appropriate spawn method

2. **Complete Station Spawn:**
   - Implement FindStationById() to locate AStationActor
   - Call Station->DockPlayer(PC)
   - Open W_StationMenu widget

3. **Complete Space Spawn:**
   - Query ship data from backend
   - Spawn ship actor at coordinates
   - Sync InventoryComponent
   - Set physics velocity and rotation

4. **HUD Integration:**
   - Create or update main HUD class
   - Subscribe to OnEntryFlowComplete
   - Remove entry widgets on event
   - Switch input mode

5. **Testing:**
   - End-to-end test full flow
   - Test both docked and space spawns
   - Test multiple characters per account
   - Test token expiration handling

---

**Implementation Status:** Core infrastructure complete (80%)
**Remaining Work:** Backend query in GameMode, station/space spawn details, HUD integration (20%)
**Last Updated:** 2026-01-31
