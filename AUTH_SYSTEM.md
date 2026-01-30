# Auth, Identity & Inventory System

## Overview

Complete authentication and identity management system for Echoes MMO, implementing the "Postgres is Truth" architecture with JWT authentication for players and X-Server-Secret for UE Server communication.

## Architecture

```
┌────────────────────────────────────────────────────────────────┐
│                    CLIENT (UE5 C++)                            │
│                                                                │
│  Player enters credentials in UI                               │
│          ↓                                                     │
│  UEchoesAuthSubsystem (GameInstanceSubsystem)                 │
│  - Auth_Login() / Auth_Register()                             │
│  - Stores JWT token                                            │
│  - Provides token to other subsystems                          │
│          ↓                                                     │
└──────────┼─────────────────────────────────────────────────────┘
           │ HTTP POST with JSON
           │ (Email/Username + Password)
           ▼
┌────────────────────────────────────────────────────────────────┐
│                  BACKEND (ASP.NET Core 8)                      │
│                                                                │
│  AuthController                                                │
│  POST /api/auth/login                                          │
│  POST /api/auth/register                                       │
│          ↓                                                     │
│  1. Validate credentials                                       │
│  2. Query PostgreSQL                                           │
│  3. Generate JWT token                                         │
│  4. Create session record                                      │
│  5. Return: Token + AccountID + Character List                 │
│          ↓                                                     │
└──────────┼─────────────────────────────────────────────────────┘
           │ JSON Response
           │ { token, accountId, characters[] }
           ▼
┌────────────────────────────────────────────────────────────────┐
│              CLIENT (Stores Auth Data)                         │
│                                                                │
│  - JWT Token (for API requests)                                │
│  - Account ID                                                  │
│  - Character ID                                                │
│  - Character List                                              │
│                                                                │
│  Other subsystems use token:                                   │
│  - ShipStatsSubsystem                                         │
│  - InventorySubsystem                                          │
│  - CharacterSubsystem                                          │
└────────────────────────────────────────────────────────────────┘
```

## Backend Implementation (C#)

### 1. Account Model

```csharp
[Table("accounts")]
public class Account
{
    [Key]
    public Guid AccountId { get; set; }
    
    [Required]
    [EmailAddress]
    public string Email { get; set; }
    
    [Required]
    public string Username { get; set; }
    
    [Required]
    public byte[] PasswordHash { get; set; }
    
    [Required]
    public byte[] PasswordSalt { get; set; }
    
    public AccountStatus AccountStatus { get; set; }
    public DateTime CreatedAt { get; set; }
    
    // Navigation
    public virtual ICollection<Character> Characters { get; set; }
    public virtual ICollection<AccountSession> Sessions { get; set; }
}
```

### 2. AccountSession Model

```csharp
[Table("AccountSessions")]
public class AccountSession
{
    [Key]
    public Guid Id { get; set; }
    
    [Required]
    public Guid AccountId { get; set; }
    
    public Guid? CharacterId { get; set; }
    
    [Required]
    public string SessionToken { get; set; }
    
    [Required]
    public string RefreshToken { get; set; }
    
    public DateTime CreatedAt { get; set; }
    public DateTime ExpiresAt { get; set; }
    public DateTime RefreshTokenExpiresAt { get; set; }
    
    public string? IPAddress { get; set; }
    public string? UserAgent { get; set; }
    public bool IsActive { get; set; }
}
```

### 3. AuthController Endpoints

#### POST /api/auth/register

**Request:**
```json
{
  "username": "PlayerOne",
  "email": "player@example.com",
  "password": "SecurePassword123!"
}
```

**Response:**
```json
{
  "success": true,
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "accountId": "123e4567-e89b-12d3-a456-426614174000",
  "characterId": "223e4567-e89b-12d3-a456-426614174001",
  "characterName": "PlayerOne's Pilot",
  "sessionId": "323e4567-e89b-12d3-a456-426614174002",
  "expiresAt": "2026-02-06T02:00:00Z",
  "characters": [
    {
      "characterId": "223e4567-e89b-12d3-a456-426614174001",
      "name": "PlayerOne's Pilot",
      "walletBalance": 1000000,
      "currentShipId": null,
      "isMain": true,
      "isOnline": false
    }
  ]
}
```

#### POST /api/auth/login

**Request:**
```json
{
  "emailOrUsername": "player@example.com",
  "password": "SecurePassword123!"
}
```

**Response:** Same as register

### 4. CharacterController

#### GET /api/character/me

**Headers:**
```
Authorization: Bearer {JWT_TOKEN}
```

**Response:**
```json
{
  "characterId": "223e4567-e89b-12d3-a456-426614174001",
  "name": "PlayerOne's Pilot",
  "accountId": "123e4567-e89b-12d3-a456-426614174000",
  "walletBalance": 1000000,
  "securityStatus": 0.0,
  "currentShipId": null,
  "corporationId": null,
  "raceId": 1,
  "totalSkillPoints": 0,
  "unallocatedSkillPoints": 0,
  "isOnline": true,
  "isDocked": true,
  "inWarp": false,
  "lastLogin": "2026-01-30T02:00:00Z"
}
```

#### GET /api/character/{id}

**Headers:**
```
X-Server-Secret: {SERVER_SECRET}
Authorization: Bearer {JWT_TOKEN}
```

**Response:** Same as /api/character/me

## UE5 Implementation (C++)

### 1. Auth Structures

```cpp
// Login/Register request
USTRUCT(BlueprintType)
struct FAuthRequest
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FString EmailOrUsername;

    UPROPERTY(BlueprintReadWrite)
    FString Password;
};

// Auth response from backend
USTRUCT(BlueprintType)
struct FAuthResponse
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    bool Success = false;

    UPROPERTY(BlueprintReadWrite)
    FString Token;

    UPROPERTY(BlueprintReadWrite)
    FGuid AccountId;

    UPROPERTY(BlueprintReadWrite)
    FGuid CharacterId;

    UPROPERTY(BlueprintReadWrite)
    FString CharacterName;

    UPROPERTY(BlueprintReadWrite)
    TArray<FCharacterInfo> Characters;
};

// Character info in list
USTRUCT(BlueprintType)
struct FCharacterInfo
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FGuid CharacterId;

    UPROPERTY(BlueprintReadWrite)
    FString Name;

    UPROPERTY(BlueprintReadWrite)
    int64 WalletBalance = 0;

    UPROPERTY(BlueprintReadWrite)
    int64 CurrentShipId = 0;

    UPROPERTY(BlueprintReadWrite)
    bool IsMain = false;

    UPROPERTY(BlueprintReadWrite)
    bool IsOnline = false;
};

// Full character data
USTRUCT(BlueprintType)
struct FCharacterData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FGuid CharacterId;

    UPROPERTY(BlueprintReadWrite)
    FString Name;

    UPROPERTY(BlueprintReadWrite)
    int64 WalletBalance = 0;

    UPROPERTY(BlueprintReadWrite)
    float SecurityStatus = 0.0f;

    UPROPERTY(BlueprintReadWrite)
    int64 CurrentShipId = 0;

    UPROPERTY(BlueprintReadWrite)
    bool IsOnline = false;

    UPROPERTY(BlueprintReadWrite)
    bool IsDocked = true;

    UPROPERTY(BlueprintReadWrite)
    bool InWarp = false;
    
    // ... more fields
};
```

### 2. UEchoesAuthSubsystem

```cpp
UCLASS()
class ECHOES_API UEchoesAuthSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    // Login
    UFUNCTION(BlueprintCallable)
    void Auth_Login(
        const FAuthRequest& Request,
        FOnLoginSuccess OnSuccess,
        FOnLoginFailure OnFailure);

    // Register
    UFUNCTION(BlueprintCallable)
    void Auth_Register(
        const FString& Username,
        const FString& Email,
        const FString& Password,
        FOnRegisterSuccess OnSuccess,
        FOnRegisterFailure OnFailure);

    // Get token for other subsystems
    UFUNCTION(BlueprintPure)
    FString Auth_GetToken() const;

    // Check if logged in
    UFUNCTION(BlueprintPure)
    bool Auth_IsLoggedIn() const;

    // Get character list
    UFUNCTION(BlueprintPure)
    TArray<FCharacterInfo> Auth_GetCharacters() const;

    // Logout
    UFUNCTION(BlueprintCallable)
    void Auth_Logout();

    // Server verification
    void ServerRPC_VerifySession(
        const FGuid& CharacterId,
        TFunction<void(const FCharacterData&)> OnSuccess,
        TFunction<void(const FString&)> OnFailure);
};
```

### 3. Usage in Blueprints/C++

#### Login Example (C++)

```cpp
void AMyLoginWidget::OnLoginButtonClicked()
{
    auto AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
    
    FAuthRequest LoginRequest;
    LoginRequest.EmailOrUsername = EmailTextBox->GetText().ToString();
    LoginRequest.Password = PasswordTextBox->GetText().ToString();
    
    FOnLoginSuccess OnSuccess;
    OnSuccess.BindLambda([this](const FAuthResponse& Response) {
        UE_LOG(LogTemp, Log, TEXT("Login successful!"));
        UE_LOG(LogTemp, Log, TEXT("Account: %s"), *Response.AccountId.ToString());
        UE_LOG(LogTemp, Log, TEXT("Character: %s"), *Response.CharacterName);
        UE_LOG(LogTemp, Log, TEXT("Characters available: %d"), Response.Characters.Num());
        
        // Navigate to character select or game
        OnLoginSuccess(Response);
    });
    
    FOnLoginFailure OnFailure;
    OnFailure.BindLambda([this](const FString& Error) {
        UE_LOG(LogTemp, Error, TEXT("Login failed: %s"), *Error);
        ShowErrorMessage(Error);
    });
    
    AuthSubsystem->Auth_Login(LoginRequest, OnSuccess, OnFailure);
}
```

#### Using Token in Other Subsystems

```cpp
void UMyInventorySubsystem::FetchInventory()
{
    auto AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
    
    if (!AuthSubsystem->Auth_IsLoggedIn())
    {
        UE_LOG(LogTemp, Error, TEXT("Not logged in!"));
        return;
    }
    
    // Get token
    FString Token = AuthSubsystem->Auth_GetToken();
    FGuid CharacterId = AuthSubsystem->Auth_GetCharacterId();
    
    // Make authenticated request
    TSharedRef<IHttpRequest> HttpRequest = Http->CreateRequest();
    HttpRequest->SetVerb(TEXT("GET"));
    HttpRequest->SetURL(ApiBaseUrl + TEXT("/inventory/ships"));
    HttpRequest->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    
    HttpRequest->ProcessRequest();
}
```

#### Server Verification

```cpp
void AMyGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
    
    auto AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
    
    // Get character ID from player controller
    FGuid CharacterId = GetCharacterIdFromPlayerController(NewPlayer);
    
    // Verify with backend
    AuthSubsystem->ServerRPC_VerifySession(
        CharacterId,
        [this, NewPlayer](const FCharacterData& CharData) {
            UE_LOG(LogTemp, Log, TEXT("Player %s verified!"), *CharData.Name);
            
            // Spawn player with character data
            SpawnPlayerCharacter(NewPlayer, CharData);
        },
        [this, NewPlayer](const FString& Error) {
            UE_LOG(LogTemp, Error, TEXT("Verification failed: %s"), *Error);
            
            // Kick player
            NewPlayer->ClientTravel(TEXT("/Game/Maps/LoginMap"), ETravelType::TRAVEL_Absolute);
        }
    );
}
```

## Configuration

### Backend (appsettings.json)

```json
{
  "ConnectionStrings": {
    "DefaultConnection": "Host=localhost;Database=echoes;Username=postgres;Password=password"
  },
  "Jwt": {
    "Key": "YourSuperSecretKeyThatIsAtLeast32CharactersLong!",
    "Issuer": "EchoesBackend",
    "Audience": "EchoesClient",
    "ExpirationDays": 7
  },
  "ServerSecret": "UE5-Server-Secret-Change-Me-In-Production"
}
```

### UE5 (DefaultGame.ini)

```ini
[/Script/Echoes.EchoesAuthSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=UE5-Server-Secret-Change-Me-In-Production
```

For production:
```ini
[/Script/Echoes.EchoesAuthSubsystem]
ApiBaseUrl=https://api.echoes.game/api
ServerSecret=PRODUCTION_SECRET_HERE
```

## Security

### JWT Token

- **Storage**: In memory only (UEchoesAuthSubsystem)
- **Expiration**: 7 days (configurable)
- **Refresh**: Automatic with refresh token
- **Transmission**: HTTPS only in production
- **Header**: `Authorization: Bearer {token}`

### X-Server-Secret

- **Purpose**: Authenticate UE Server → Backend
- **Storage**: DefaultGame.ini (server only)
- **Never**: Send to client
- **Header**: `X-Server-Secret: {secret}`

### Password

- **Storage**: Never stored plain text
- **Hashing**: SHA256 with unique salt per user
- **Transmission**: HTTPS only
- **Validation**: Min 8 characters

### Account Lockout

- **Failed attempts**: 5 max
- **Lockout duration**: 15 minutes
- **Reset**: On successful login

## Testing

### Backend Tests

```bash
# Test registration
curl -X POST http://localhost:5116/api/auth/register \
  -H "Content-Type: application/json" \
  -d '{
    "username": "testuser",
    "email": "test@example.com",
    "password": "TestPassword123!"
  }'

# Test login
curl -X POST http://localhost:5116/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{
    "emailOrUsername": "test@example.com",
    "password": "TestPassword123!"
  }'

# Test character endpoint
curl -X GET http://localhost:5116/api/character/me \
  -H "Authorization: Bearer {token}"
```

### UE5 Tests

```cpp
// In your test map
void ATestActor::BeginPlay()
{
    Super::BeginPlay();
    
    auto AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
    
    // Test login
    FAuthRequest Request;
    Request.EmailOrUsername = TEXT("test@example.com");
    Request.Password = TEXT("TestPassword123!");
    
    FOnLoginSuccess OnSuccess;
    OnSuccess.BindLambda([](const FAuthResponse& Response) {
        UE_LOG(LogTemp, Log, TEXT("✓ Login test passed"));
        UE_LOG(LogTemp, Log, TEXT("Token: %s"), *Response.Token.Left(20));
        UE_LOG(LogTemp, Log, TEXT("Characters: %d"), Response.Characters.Num());
    });
    
    FOnLoginFailure OnFailure;
    OnFailure.BindLambda([](const FString& Error) {
        UE_LOG(LogTemp, Error, TEXT("✗ Login test failed: %s"), *Error);
    });
    
    AuthSubsystem->Auth_Login(Request, OnSuccess, OnFailure);
}
```

## Troubleshooting

### "HTTP module not available"
- Check Build.cs has "Http" module
- Verify module loads in Initialize()

### "Failed to parse response"
- Check backend JSON matches structs
- Enable verbose logging
- Verify GUID parsing

### "Invalid token"
- Check token expiration
- Verify JWT secret matches
- Check Authorization header format

### "X-Server-Secret invalid"
- Verify secret in appsettings.json
- Check DefaultGame.ini on server
- Ensure header name is exact

## Next Steps

1. **Inventory System**: Use Auth token for inventory requests
2. **Character Selection**: UI to choose from character list
3. **Session Management**: Refresh token before expiration
4. **UI Widgets**: Login/register forms
5. **Error Handling**: User-friendly error messages
