# Complete Game Login Flow - Implementation Summary

## Overview
This document describes the complete three-stage game login flow implementation for Echoes MMO, including cold start validation, authentication, character selection, and regional server connection.

## Three-Stage Login Flow

### Stage 1: Preload (W_Preload) - Cold Start
**Purpose:** Verify API connectivity and validate saved credentials

**Flow:**
1. Check API health: `GET /api/system/status`
2. If token exists in LocalPlayerSettings:
   - Validate token: `POST /api/auth/validate-token`
   - On success → Character Select (Stage 3)
   - On failure → Login (Stage 2)
3. If no token → Login (Stage 2)

**Implementation:** `EchoesPreloadWidget.h/cpp`
- Inherits from `UEchoesWindowBase`
- Displays progress bar and status messages
- Automatically transitions to next stage
- Event: `OnPreloadComplete(ENextState NextState)`

### Stage 2: Login (W_Login) - Authentication
**Purpose:** Exchange credentials for JWT token

**Features:**
- Email/Username and Password input fields
- "Remember Me" checkbox for token persistence
- Login and Register buttons
- Status messages with color coding

**Flow:**
1. User enters credentials
2. POST to `/api/auth/login`
3. On success:
   - Store JWT in `UEchoesAuthSubsystem`
   - If "Remember Me": Save token to LocalPlayerSettings
   - Set Authorization header for future requests
   - → Character Select (Stage 3)

**Implementation:** `EchoesLoginWidget.h/cpp`
- Inherits from `UEchoesWindowBase`
- Integration with `UEchoesAuthSubsystem`
- Event: `OnLoginSuccessDelegate`

### Stage 3: Character Select (W_CharacterSelect) - World Entry
**Purpose:** Select or create character, connect to regional server

**Features:**
- List existing characters: `GET /api/character/list`
- Create new character with race selection
- Race descriptions and bonuses
- "Enter World" button

**Flow:**
1. Display character list from AuthSubsystem
2. **New Player Flow:**
   - Show race selection UI
   - POST to `/api/character/create` with Name and RaceId
   - Server assigns StartingStationId based on race
3. **Enter World:**
   - Save SelectedCharacterId in GameInstance
   - GET `/api/character/{id}/connect-info`
   - Receive: ServerIP, SystemId, IsDocked flag
   - Execute `ClientTravel(ServerIP, TRAVEL_Relative)`

**Implementation:** `EchoesCharacterSelectWidget.h/cpp`
- Inherits from `UEchoesWindowBase`
- ListView for character display
- Race combo box with dynamic info display

## Backend API Endpoints

### System Endpoints

#### GET /api/system/status
Health check for API connectivity
```json
Response: {
  "status": "online",
  "timestamp": "2026-01-31T...",
  "database": "connected",
  "version": "1.0.0"
}
```

### Authentication Endpoints

#### POST /api/auth/validate-token
Validate saved JWT token
```json
Request: { "token": "..." }
Response: {
  "isValid": true,
  "accountId": "guid",
  "characterId": "guid",
  "characterName": "string",
  "characters": [...]
}
```

#### POST /api/auth/login
Existing endpoint - returns JWT token and character list

### Character Endpoints

#### GET /api/character/list
Returns array of player's characters
```json
Response: [{
  "characterId": "guid",
  "name": "string",
  "raceId": 1,
  "raceName": "Caldari",
  "walletBalance": 5000000,
  "isMain": true,
  "isDocked": true,
  "homeStationId": "guid"
}]
```

#### POST /api/character/create
Creates new character with race-based starting location
```json
Request: {
  "name": "CharacterName",
  "raceId": 1,
  "portraitId": 1
}
Response: { CharacterDataDto }
```

#### GET /api/character/{id}/connect-info
Returns regional server connection information
```json
Response: {
  "characterId": "guid",
  "characterName": "string",
  "serverIP": "127.0.0.1",
  "serverPort": 7777,
  "systemId": "guid",
  "systemName": "Jita",
  "isDocked": true,
  "stationId": "guid",
  "connectionToken": "one-time-token"
}
```

## UE5 Architecture

### Widget Hierarchy
All game UI widgets inherit from `UEchoesWindowBase`:
- Provides draggable window behavior
- Z-order focus management
- Consistent window styling
- Close button functionality

Widget inheritance:
```
UEchoesWindowBase (base class)
├── UEchoesPreloadWidget
├── UEchoesLoginWidget
└── UEchoesCharacterSelectWidget
```

### Auth Subsystem Structure

**UEchoesAuthSubsystem** (GameInstanceSubsystem)
```cpp
// Current implementation
- FString JWTToken
- FAuthResponse CurrentAuthResponse
- TArray<FCharacterInfo> Characters

// Methods
- Auth_Login()
- Auth_Register()
- Auth_GetToken()
- Auth_GetCharacterId()
- Auth_GetCharacters()
- Auth_Logout()
```

**TODO: FCurrentSessionData** structure
```cpp
struct FCurrentSessionData
{
    FString Token;
    FGuid CharacterId;
    FGuid LastStationId;
    FGuid LastSystemId;
    bool bIsValid;
};
```

### GameMode Integration

**AEchoesServerGameMode** - Server-side spawn logic

**PostLogin Flow:**
1. Extract connection token from login parameters
2. Validate token with backend: `POST /api/auth/validate`
3. Query character location: `GET /api/character/{id}/location`
4. **If IsDocked:**
   - Place player in "docking state"
   - Find StationActor by StationId
   - Open W_StationMenu
5. **If in space:**
   - Spawn player's ship at LastSavedTransform
   - Load ship fitting from inventory
   - Set velocity and orientation

**Implementation Status:**
- ✅ Framework in place (`SpawnPlayerAtLocation`)
- ⚠️ Token validation integration pending
- ⚠️ Station docking logic pending
- ⚠️ Space spawn logic pending

## Race Configuration System

**Backend (RaceConfig table):**
```
RaceId | RaceName  | StartingStationId | DefaultShipTypeId | StartingISK
-------|-----------|-------------------|-------------------|------------
1      | Caldari   | guid              | 670 (Ibis)       | 5000000
2      | Gallente  | guid              | 606 (Velator)    | 5000000
3      | Amarr     | guid              | 596 (Impairor)   | 5000000
4      | Minmatar  | guid              | 588 (Reaper)     | 5000000
```

**Race Bonuses:**
- Caldari: Shield HP, Hybrid weapons, Electronic warfare
- Gallente: Armor HP, Drones, Scan resolution
- Amarr: Armor HP, Energy weapons, Capacitor
- Minmatar: Shield HP, Projectile weapons, Velocity

## Token Persistence (TODO)

### LocalPlayerSettings Integration
Location: `SavedData/LocalPlayerSettings.sav`

```cpp
// TODO: Implement
class ULocalPlayerSettings
{
    FString SavedJWTToken;
    bool bRememberMe;
    FDateTime TokenExpiration;
    
    void SaveToken(const FString& Token);
    FString LoadToken();
    void ClearToken();
};
```

## ClientTravel Implementation

### Connect Info Response Processing
```cpp
void UEchoesCharacterSelectWidget::OnConnectInfoReceived(...)
{
    // Parse response
    FString ServerAddress = FString::Printf(
        TEXT("%s:%d"),
        *ConnectInfo.ServerIP,
        ConnectInfo.ServerPort
    );
    
    // Save character ID in GameInstance
    UMyGameInstance* GI = Cast<UMyGameInstance>(GetGameInstance());
    GI->SetSelectedCharacterId(ConnectInfo.CharacterId);
    GI->SetConnectionToken(ConnectInfo.ConnectionToken);
    
    // Travel to regional server
    GetWorld()->GetFirstPlayerController()->ClientTravel(
        ServerAddress,
        TRAVEL_Relative
    );
}
```

### Connection Parameters
Regional server receives:
- CharacterId (from GameInstance)
- ConnectionToken (one-time token for validation)
- SystemId (target solar system)

## OnEntryFlowComplete Delegate

**Purpose:** Signal when UI flow is complete and game world should take control

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEntryFlowComplete);

// In GameMode or PlayerController
UPROPERTY(BlueprintAssignable)
FOnEntryFlowComplete OnEntryFlowComplete;

// Usage
void AMyGameMode::CompleteSpawn()
{
    OnEntryFlowComplete.Broadcast();
    
    // Hide UI layer
    PlayerController->SetShowMouseCursor(false);
    PlayerController->SetInputMode(FInputModeGameOnly());
}
```

## Implementation Checklist

### Backend - COMPLETED ✅
- [x] SystemController with status endpoint
- [x] Auth validate-token endpoint
- [x] Character connect-info endpoint
- [x] Race configuration system
- [x] Character creation with race support
- [x] DTOs for all new endpoints

### UE5 - PARTIALLY COMPLETED
- [x] W_Preload widget
- [x] W_Login with Remember Me
- [x] W_CharacterSelect UI
- [x] All widgets inherit from UEchoesWindowBase
- [ ] LocalPlayerSettings for token persistence
- [ ] HTTP calls for character creation
- [ ] HTTP calls for connect-info
- [ ] ClientTravel implementation
- [ ] GameMode token validation
- [ ] Station docking logic
- [ ] Space spawn logic
- [ ] OnEntryFlowComplete delegate

### Testing Requirements
- [ ] Test full flow: Preload → Login → Character Select → Spawn
- [ ] Test "Remember Me" functionality
- [ ] Test cold start with valid token
- [ ] Test cold start with expired token
- [ ] Test character creation for each race
- [ ] Test docked spawn (station menu opens)
- [ ] Test space spawn (ship spawns at coordinates)
- [ ] Test regional server connection
- [ ] Test token expiration during gameplay

## Known Issues & Limitations

1. **LocalPlayerSettings not implemented** - Token persistence uses AuthSubsystem only
2. **Character creation HTTP incomplete** - UI exists but API call not wired
3. **connect-info not called** - CharacterSelect doesn't request server info yet
4. **ClientTravel not implemented** - No regional server connection logic
5. **GameMode spawn incomplete** - Token validation and location-based spawn pending
6. **Database migration pending** - Pre-existing build errors block migration
7. **Race data duplicated** - Client has hardcoded race info (should fetch from API)

## Security Considerations

- JWT tokens stored in memory only (not disk by default)
- "Remember Me" will save encrypted token to LocalPlayerSettings
- Connection tokens are one-time use
- Server validates all tokens before spawning
- Character ownership verified via JWT claims
- SQL injection prevented via parameterized queries
- Password hashing with HMACSHA512

## Performance Considerations

- Preload widget minimizes startup delay
- Token validation async (non-blocking UI)
- Character list cached in AuthSubsystem
- Race configs loaded from database (not per-request)
- Regional server assignment based on solar system
- Connection pooling for database queries

---

**Status:** Core backend complete, UE5 framework in place, full integration pending
**Last Updated:** 2026-01-31
**Branch:** copilot/implement-authentication-and-character-selection
