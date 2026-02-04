# Identity & Inventory Subsystems Documentation

## Overview

This document describes the **UEchoesIdentitySubsystem** and **UEchoesInventorySubsystem** implementation for the Echoes MMO, providing character management and ship/module inventory functionality with full backend integration.

## Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                        UE5 Client                            │
├─────────────────────────────────────────────────────────────┤
│                                                               │
│  ┌──────────────────┐    ┌──────────────────┐               │
│  │ EchoesAuth       │◄───┤ EchoesIdentity   │               │
│  │ Subsystem        │    │ Subsystem        │               │
│  │ (JWT Token)      │    │ (Characters)     │               │
│  └────────┬─────────┘    └──────────────────┘               │
│           │                                                  │
│           │JWT              ┌──────────────────┐            │
│           └────────────────►│ EchoesInventory  │            │
│                              │ Subsystem        │            │
│                              │ (Ships/Modules)  │            │
│                              └──────────────────┘            │
└─────────────────────────────────────────────────────────────┘
                               │ HTTP + JWT
                               ▼
┌─────────────────────────────────────────────────────────────┐
│                    ASP.NET Core Backend                      │
├─────────────────────────────────────────────────────────────┤
│                                                               │
│  /api/character/me          [Authorize]                      │
│  /api/inventory/ships       [Authorize]                      │
│  /api/inventory/ship/{id}/fitting  [Authorize]               │
│  /api/inventory/ship/{id}/activate [Authorize]               │
│                                                               │
└─────────────────────────────────────────────────────────────┘
                               │
                               ▼
                         [PostgreSQL]
```

## Identity Subsystem

### Purpose

Manages character selection and retrieval. Provides character data to UI and gameplay systems.

### Key Features

- **Character Data Retrieval**: Fetch current character from backend
- **Character Selection**: Track which character is currently active
- **Session Validation**: Verify character before entering world
- **JWT Integration**: Uses token from Auth subsystem

### Data Structures

#### FEchoesCharacter

Mirrors C# `CharacterDataDto`:

```cpp
struct FEchoesCharacter
{
    FGuid CharacterId;
    FString Name;
    FGuid AccountId;
    int64 WalletBalance;      // Credits balance
    int64 Credits;            // Alias for WalletBalance
    float SecurityStatus;
    int64 CurrentShipId;
    FGuid CorporationId;
    int32 RaceId;
    int32 TotalSkillPoints;
    int32 UnallocatedSkillPoints;
    bool IsOnline;
    bool IsDocked;
    bool InWarp;
    FDateTime LastLogin;
    FString PortraitURL;
};
```

### API Functions

#### Identity_FetchCharacter

Fetch current character data from backend.

```cpp
void Identity_FetchCharacter(
    FOnCharacterDataReceived OnSuccess,
    FOnCharacterDataFailure OnFailure
);
```

**Usage:**
```cpp
auto IdentitySubsystem = GetGameInstance()->GetSubsystem<UEchoesIdentitySubsystem>();

IdentitySubsystem->Identity_FetchCharacter(
    FOnCharacterDataReceived::CreateLambda([](const FEchoesCharacter& Character) {
        UE_LOG(LogTemp, Log, TEXT("Character: %s"), *Character.Name);
        UE_LOG(LogTemp, Log, TEXT("Credits Balance: %lld"), Character.Credits);
        UE_LOG(LogTemp, Log, TEXT("Security Status: %.2f"), Character.SecurityStatus);
        UE_LOG(LogTemp, Log, TEXT("Skill Points: %d"), Character.TotalSkillPoints);
    }),
    FOnCharacterDataFailure::CreateLambda([](const FString& Error) {
        UE_LOG(LogTemp, Error, TEXT("Failed to fetch character: %s"), *Error);
    })
);
```

#### Identity_SelectCharacter

Select a character and notify the system.

```cpp
void Identity_SelectCharacter(const FGuid& CharacterId);
```

**Usage:**
```cpp
// Select from character list in login response
auto AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
TArray<FCharacterInfo> Characters = AuthSubsystem->Auth_GetCharacters();

if (Characters.Num() > 0)
{
    // Select first character
    IdentitySubsystem->Identity_SelectCharacter(Characters[0].CharacterId);
}
```

#### Identity_GetSelectedCharacter

Get the currently selected character.

```cpp
FEchoesCharacter Identity_GetSelectedCharacter() const;
```

#### Identity_HasSelectedCharacter

Check if a character is selected.

```cpp
bool Identity_HasSelectedCharacter() const;
```

#### Identity_ClearSelection

Clear selected character (logout).

```cpp
void Identity_ClearSelection();
```

### Delegates

#### OnCharacterSelected

Broadcast when a character is selected.

```cpp
UPROPERTY(BlueprintAssignable)
FOnCharacterSelected OnCharacterSelected;
```

**Usage:**
```cpp
IdentitySubsystem->OnCharacterSelected.AddLambda([]() {
    UE_LOG(LogTemp, Log, TEXT("Character selected! Loading hangar..."));
});
```

---

## Inventory Subsystem

### Purpose

Manages ship hangar and fitting. Provides ship and module data to Movement Component and UI.

### Key Features

- **Ship List**: Fetch all ships owned by character
- **Ship Fitting**: Get detailed fitting with all modules
- **Ship Activation**: Set active ship for undocking
- **Cache Management**: Store fetched data for offline access
- **Physics Integration**: Fitting data used by Movement Component

### Data Structures

#### FEchoesShipInstance

Mirrors C# `ShipInstanceDto`:

```cpp
struct FEchoesShipInstance
{
    FGuid InstanceId;
    FString Name;
    int32 ShipTypeId;
    FString ShipTypeName;
    float Mass;
    FGuid LocationSystemId;
    FString LocationName;
    bool IsActive;
    bool IsDocked;
    int32 ModuleCount;
};
```

#### FEchoesModule

Mirrors C# `ModuleInstanceDto`:

```cpp
struct FEchoesModule
{
    FGuid InstanceId;
    int32 ModuleTypeId;
    FString TypeName;
    FString SlotType;
    int32 SlotIndex;
    bool IsOnline;
    float Mass;
    float ThrustBonus;
    float InertiaModifier;
    float RotationBonus;
    float MaxVelocityModifier;
};
```

#### FEchoesShipFitting

Mirrors C# `ShipFittingDto`:

```cpp
struct FEchoesShipFitting
{
    FGuid ShipInstanceId;
    FString ShipName;
    int32 ShipTypeId;
    FString ShipTypeName;
    float BaseMass;
    float TotalMass;           // BaseMass + Σ ModuleMass
    float Thrust;              // BaseThrust + Σ ThrustBonus
    float MaxVelocity;         // BaseVelocity * Π MaxVelocityModifier
    float InertiaMultiplier;   // BaseInertia * Π InertiaModifier
    float RotationTorque;      // BaseRotation + Σ RotationBonus
    TArray<FEchoesModule> Modules;
};
```

### API Functions

#### Inventory_FetchShips

Fetch all ships for current character.

```cpp
void Inventory_FetchShips(
    FOnShipsReceived OnSuccess,
    FOnInventoryFailure OnFailure
);
```

**Usage:**
```cpp
auto InventorySubsystem = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();

InventorySubsystem->Inventory_FetchShips(
    FOnShipsReceived::CreateLambda([](const TArray<FEchoesShipInstance>& Ships) {
        UE_LOG(LogTemp, Log, TEXT("Found %d ships"), Ships.Num());
        
        for (const auto& Ship : Ships)
        {
            UE_LOG(LogTemp, Log, TEXT("- %s (%s) - %s"),
                *Ship.Name,
                *Ship.ShipTypeName,
                Ship.IsActive ? TEXT("ACTIVE") : TEXT("Docked"));
        }
    }),
    FOnInventoryFailure::CreateLambda([](const FString& Error) {
        UE_LOG(LogTemp, Error, TEXT("Failed to fetch ships: %s"), *Error);
    })
);
```

#### Inventory_FetchShipFitting

Fetch detailed ship fitting with all modules.

**This data is crucial for initializing the Movement Component physics!**

```cpp
void Inventory_FetchShipFitting(
    const FGuid& ShipId,
    FOnShipFittingReceived OnSuccess,
    FOnInventoryFailure OnFailure
);
```

**Usage:**
```cpp
// Get active ship
FEchoesShipInstance ActiveShip = InventorySubsystem->Inventory_GetActiveShip();

if (ActiveShip.InstanceId.IsValid())
{
    // Fetch fitting for Movement Component initialization
    InventorySubsystem->Inventory_FetchShipFitting(
        ActiveShip.InstanceId,
        FOnShipFittingReceived::CreateLambda([this](const FEchoesShipFitting& Fitting) {
            UE_LOG(LogTemp, Log, TEXT("Ship: %s"), *Fitting.ShipName);
            UE_LOG(LogTemp, Log, TEXT("Total Mass: %.0f kg"), Fitting.TotalMass);
            UE_LOG(LogTemp, Log, TEXT("Thrust: %.0f N"), Fitting.Thrust);
            UE_LOG(LogTemp, Log, TEXT("Max Velocity: %.2f m/s"), Fitting.MaxVelocity);
            UE_LOG(LogTemp, Log, TEXT("Inertia: %.4f"), Fitting.InertiaMultiplier);
            UE_LOG(LogTemp, Log, TEXT("Modules: %d"), Fitting.Modules.Num());
            
            // Apply to Movement Component
            if (ShipPawn && ShipPawn->MovementComponent)
            {
                ShipPawn->MovementComponent->ApplyShipStats(
                    Fitting.TotalMass,
                    Fitting.Thrust,
                    Fitting.InertiaMultiplier,
                    Fitting.RotationTorque,
                    Fitting.MaxVelocity
                );
            }
        }),
        FOnInventoryFailure::CreateLambda([](const FString& Error) {
            UE_LOG(LogTemp, Error, TEXT("Failed to fetch fitting: %s"), *Error);
        })
    );
}
```

#### Inventory_SetActiveShip

Activate a ship (prepare for undocking).

```cpp
void Inventory_SetActiveShip(
    const FGuid& ShipId,
    FOnShipActivated OnSuccess,
    FOnInventoryFailure OnFailure
);
```

**Usage:**
```cpp
// User selects ship from hangar UI
FGuid SelectedShipId = /* from UI selection */;

InventorySubsystem->Inventory_SetActiveShip(
    SelectedShipId,
    FOnShipActivated::CreateLambda([]() {
        UE_LOG(LogTemp, Log, TEXT("Ship activated! Ready to undock."));
        // Show undock button in UI
    }),
    FOnInventoryFailure::CreateLambda([](const FString& Error) {
        UE_LOG(LogTemp, Error, TEXT("Failed to activate ship: %s"), *Error);
    })
);
```

#### Inventory_GetCachedShips

Get cached ships list (no network request).

```cpp
TArray<FEchoesShipInstance> Inventory_GetCachedShips() const;
```

#### Inventory_GetCachedFitting

Get cached ship fitting (no network request).

```cpp
FEchoesShipFitting Inventory_GetCachedFitting() const;
```

#### Inventory_GetActiveShip

Get the currently active ship from cached list.

```cpp
FEchoesShipInstance Inventory_GetActiveShip() const;
```

#### Inventory_ClearCache

Clear inventory cache.

```cpp
void Inventory_ClearCache();
```

---

## Integration Examples

### Complete Login Flow

```cpp
void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();
    
    auto GameInstance = GetGameInstance();
    auto AuthSubsystem = GameInstance->GetSubsystem<UEchoesAuthSubsystem>();
    auto IdentitySubsystem = GameInstance->GetSubsystem<UEchoesIdentitySubsystem>();
    auto InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>();
    
    // Step 1: Login
    FAuthRequest LoginRequest;
    LoginRequest.EmailOrUsername = "pilot@echoes.com";
    LoginRequest.Password = "password123";
    
    AuthSubsystem->Auth_Login(
        LoginRequest,
        FOnLoginSuccess::CreateLambda([=](const FAuthResponse& Response) {
            UE_LOG(LogTemp, Log, TEXT("Logged in as: %s"), *Response.CharacterName);
            
            // Step 2: Fetch full character data
            IdentitySubsystem->Identity_FetchCharacter(
                FOnCharacterDataReceived::CreateLambda([=](const FEchoesCharacter& Character) {
                    UE_LOG(LogTemp, Log, TEXT("Character loaded: %s"), *Character.Name);
                    
                    // Step 3: Fetch ships
                    InventorySubsystem->Inventory_FetchShips(
                        FOnShipsReceived::CreateLambda([=](const TArray<FEchoesShipInstance>& Ships) {
                            UE_LOG(LogTemp, Log, TEXT("Loaded %d ships"), Ships.Num());
                            
                            // Step 4: Get active ship fitting
                            FEchoesShipInstance ActiveShip = InventorySubsystem->Inventory_GetActiveShip();
                            if (ActiveShip.InstanceId.IsValid())
                            {
                                InventorySubsystem->Inventory_FetchShipFitting(
                                    ActiveShip.InstanceId,
                                    FOnShipFittingReceived::CreateLambda([](const FEchoesShipFitting& Fitting) {
                                        UE_LOG(LogTemp, Log, TEXT("Ready to undock in %s"), *Fitting.ShipName);
                                        // Show game UI
                                    }),
                                    FOnInventoryFailure::CreateLambda([](const FString& Error) {
                                        UE_LOG(LogTemp, Error, TEXT("Fitting error: %s"), *Error);
                                    })
                                );
                            }
                        }),
                        FOnInventoryFailure::CreateLambda([](const FString& Error) {
                            UE_LOG(LogTemp, Error, TEXT("Ships error: %s"), *Error);
                        })
                    );
                }),
                FOnCharacterDataFailure::CreateLambda([](const FString& Error) {
                    UE_LOG(LogTemp, Error, TEXT("Character error: %s"), *Error);
                })
            );
        }),
        FOnLoginFailure::CreateLambda([](const FString& Error) {
            UE_LOG(LogTemp, Error, TEXT("Login failed: %s"), *Error);
        })
    );
}
```

### Ship Change Flow

```cpp
void AHangarUI::OnShipSelected(FGuid ShipId)
{
    auto InventorySubsystem = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();
    
    // Activate selected ship
    InventorySubsystem->Inventory_SetActiveShip(
        ShipId,
        FOnShipActivated::CreateLambda([=]() {
            UE_LOG(LogTemp, Log, TEXT("Ship activated"));
            
            // Fetch fitting for new ship
            InventorySubsystem->Inventory_FetchShipFitting(
                ShipId,
                FOnShipFittingReceived::CreateLambda([](const FEchoesShipFitting& Fitting) {
                    // Update UI with new ship stats
                    UpdateShipStatsUI(Fitting);
                }),
                FOnInventoryFailure::CreateLambda([](const FString& Error) {
                    UE_LOG(LogTemp, Error, TEXT("Error: %s"), *Error);
                })
            );
        }),
        FOnInventoryFailure::CreateLambda([](const FString& Error) {
            UE_LOG(LogTemp, Error, TEXT("Activation failed: %s"), *Error);
        })
    );
}
```

### Movement Component Integration

```cpp
void AEchoesShipPawn::InitializeShip()
{
    auto InventorySubsystem = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();
    
    // Get cached fitting (fetched during login)
    FEchoesShipFitting Fitting = InventorySubsystem->Inventory_GetCachedFitting();
    
    if (Fitting.ShipInstanceId.IsValid())
    {
        // Apply stats to Movement Component
        if (MovementComponent)
        {
            FEchoesShipStats Stats;
            Stats.TotalMass = Fitting.TotalMass;
            Stats.ThrustForce = Fitting.Thrust;
            Stats.InertiaMultiplier = Fitting.InertiaMultiplier;
            Stats.RotationTorque = Fitting.RotationTorque;
            Stats.MaxVelocity = Fitting.MaxVelocity;
            
            MovementComponent->SetShipStats(Stats);
            
            // Apply linear damping for EVE-style max velocity
            ShipMesh->SetLinearDamping(Fitting.InertiaMultiplier);
            
            UE_LOG(LogTemp, Log, TEXT("Ship physics initialized:"));
            UE_LOG(LogTemp, Log, TEXT("  Mass: %.0f kg"), Stats.TotalMass);
            UE_LOG(LogTemp, Log, TEXT("  Thrust: %.0f N"), Stats.ThrustForce);
            UE_LOG(LogTemp, Log, TEXT("  Max Velocity: %.2f m/s"), Stats.MaxVelocity);
        }
    }
}
```

---

## Backend API Reference

### GET /api/character/me

Get current character data.

**Authentication**: JWT required (Authorization: Bearer {token})

**Response**: `CharacterDataDto`

```json
{
  "characterId": "guid",
  "name": "Pilot Name",
  "accountId": "guid",
  "walletBalance": 1000000,
  "securityStatus": 0.0,
  "currentShipId": 123,
  "corporationId": "guid",
  "raceId": 1,
  "totalSkillPoints": 50000,
  "unallocatedSkillPoints": 5000,
  "isOnline": true,
  "isDocked": true,
  "inWarp": false,
  "lastLogin": "2024-01-01T12:00:00Z"
}
```

### GET /api/inventory/ships

List all ships for current character.

**Authentication**: JWT required

**Response**: `Array<ShipInstanceDto>`

```json
[
  {
    "instanceId": "guid",
    "name": "My Frigate",
    "shipTypeId": 101,
    "shipTypeName": "Rifter",
    "mass": 1000000.0,
    "locationSystemId": "guid",
    "locationName": "Jita IV - Moon 4",
    "isActive": true,
    "isDocked": false,
    "moduleCount": 5
  }
]
```

### GET /api/inventory/ship/{id}/fitting

Get detailed ship fitting with all modules.

**Authentication**: JWT required

**Response**: `ShipFittingDto`

```json
{
  "shipInstanceId": "guid",
  "shipName": "My Frigate",
  "shipTypeId": 101,
  "shipTypeName": "Rifter",
  "baseMass": 1000000.0,
  "totalMass": 1580000.0,
  "thrust": 650000.0,
  "maxVelocity": 126.0,
  "inertiaMultiplier": 0.9,
  "rotationTorque": 50000.0,
  "modules": [
    {
      "instanceId": "guid",
      "moduleTypeId": 201,
      "typeName": "1600mm Steel Plates",
      "slot": "Low",
      "slotIndex": 0,
      "isOnline": true,
      "mass": 500000.0,
      "thrustBonus": 0.0,
      "inertiaModifier": 1.1,
      "rotationBonus": 0.0,
      "maxVelocityModifier": 0.85
    }
  ]
}
```

### POST /api/inventory/ship/{id}/activate

Activate a ship (set as current active ship).

**Authentication**: JWT required

**Response**:

```json
{
  "success": true,
  "message": "Ship My Frigate activated",
  "shipId": "guid"
}
```

---

## Error Handling

All subsystem functions use delegates for error handling:

### Common Error Codes

- **401 Unauthorized**: JWT token invalid or expired
  - Solution: Re-authenticate with Auth_Login
- **404 Not Found**: Character/Ship not found
  - Solution: Verify IDs, refresh data
- **500 Internal Server Error**: Backend error
  - Solution: Check backend logs, retry

### Error Handling Pattern

```cpp
InventorySubsystem->Inventory_FetchShips(
    FOnShipsReceived::CreateLambda([](const TArray<FEchoesShipInstance>& Ships) {
        // Success
    }),
    FOnInventoryFailure::CreateLambda([](const FString& Error) {
        if (Error.Contains(TEXT("401")) || Error.Contains(TEXT("Authentication")))
        {
            // Token expired - re-login
            ShowLoginScreen();
        }
        else if (Error.Contains(TEXT("404")))
        {
            // Not found - show message
            ShowErrorMessage(TEXT("Character or ship not found"));
        }
        else
        {
            // Other error
            ShowErrorMessage(Error);
        }
    })
);
```

---

## Configuration

Both subsystems read configuration from `DefaultGame.ini`:

```ini
[/Script/Echoes.EchoesAuthSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=UE5-Server-Secret-Change-Me-In-Production
```

---

## Testing

### Unit Test Example

```cpp
void TestIdentitySubsystem()
{
    // Arrange
    auto GameInstance = /* get game instance */;
    auto IdentitySubsystem = GameInstance->GetSubsystem<UEchoesIdentitySubsystem>();
    
    // Act
    bool bSuccess = false;
    IdentitySubsystem->Identity_FetchCharacter(
        FOnCharacterDataReceived::CreateLambda([&](const FEchoesCharacter& Character) {
            bSuccess = Character.CharacterId.IsValid();
        }),
        FOnCharacterDataFailure::CreateLambda([](const FString& Error) {
            // Handle error
        })
    );
    
    // Wait for async operation...
    
    // Assert
    check(bSuccess);
}
```

---

## Performance Considerations

1. **Caching**: Both subsystems cache data to reduce network calls
2. **Async Operations**: All HTTP requests are asynchronous
3. **JSON Parsing**: Efficient parsing with error handling
4. **Memory Management**: Uses UE's UPROPERTY() for GC

---

## Security

1. **JWT Tokens**: Never store in plaintext, use Auth subsystem
2. **HTTPS**: Use HTTPS in production (configure ApiBaseUrl)
3. **Token Refresh**: Implement token refresh when expired
4. **Server Secret**: Keep X-Server-Secret secure for UE Server

---

## Future Enhancements

- [ ] Offline mode with local cache
- [ ] Ship fitting modification API
- [ ] Module activation/deactivation
- [ ] Cargo management
- [ ] Ship transfer between locations
- [ ] Real-time ship status updates via WebSockets

---

## Troubleshooting

### "Auth subsystem not found"

**Cause**: Auth subsystem not initialized or wrong game instance

**Solution**: Ensure you're using the correct game instance:
```cpp
UGameInstance* GameInstance = GetWorld()->GetGameInstance();
```

### "Failed to parse JSON"

**Cause**: Backend response format doesn't match expected structure

**Solution**: Enable detailed logging and check backend response:
```cpp
UE_LOG(LogTemp, Warning, TEXT("Response: %s"), *Response->GetContentAsString());
```

### "Request failed"

**Cause**: Network connectivity or backend not running

**Solution**: Verify backend is running and ApiBaseUrl is correct

---

## Summary

The Identity and Inventory subsystems provide:

✅ Complete character management
✅ Ship hangar and fitting management
✅ Seamless backend integration
✅ JWT authentication
✅ Cache management
✅ Physics integration for Movement Component
✅ EVE-style ship customization
✅ Production-ready error handling

These subsystems form the foundation for MMO gameplay, connecting player identity, ship ownership, and physics-based movement in a secure, scalable architecture.
