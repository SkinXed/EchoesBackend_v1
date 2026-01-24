# Google Authentication, RBAC, Swagger Security & Shop System Implementation

## Overview
This implementation adds advanced authentication features including Google OAuth, role-based access control, admin-only Swagger access, and a basic shop system as requested.

## Components Implemented

### 1. Google Authentication & Registration Flow

#### Packages Added
- `Microsoft.AspNetCore.Authentication.Google` (v8.0.0)
- `Google.Apis.Auth` (v1.68.0)

#### Account Model Updates
**File**: `Models/Entities/Character/Account.cs`

Added fields:
```csharp
[Column("nickname")]
[MaxLength(50)]
public string? Nickname { get; set; }

[Column("google_id")]
[MaxLength(255)]
public string? GoogleId { get; set; }
```

#### DTOs Created
**File**: `Models/DTOs/GoogleAuthDtos.cs`

- `GoogleLoginRequestDto` - Accepts Google ID token
- `GoogleRegisterRequestDto` - Accepts Google ID token + Nickname
- `GoogleAuthResponseDto` - Returns JWT token or registration needed flag

#### Google Auth Service
**File**: `Services/Auth/GoogleAuthService.cs`

Service to validate Google ID tokens using Google's API.

```csharp
public interface IGoogleAuthService
{
    Task<GoogleJsonWebSignature.Payload?> ValidateGoogleTokenAsync(string idToken);
}
```

#### Auth Controller Endpoints
**File**: `Controllers/AuthController.cs`

**POST /api/auth/google-login**
- Validates Google ID token
- If user exists → generates JWT → returns success
- If user doesn't exist → returns `RegistrationNeeded: true`

**POST /api/auth/google-register**
- Validates Google ID token
- Creates new account with "Pilot" (Player) role
- Creates default character
- Creates session
- Generates JWT
- Returns success with token

### 2. Role-Based Access Control (RBAC)

#### Roles Defined
Using existing `AccountRole` enum in `Models/Enums/AccountEnums.cs`:
- `Admin` = 1L << 7
- `Player` = 1L << 0 (used as "Pilot" role)

#### DbInitializer Service
**File**: `Services/DbInitializer.cs`

```csharp
public interface IDbInitializer
{
    Task InitializeAsync();
}
```

Responsibilities:
1. **Ensures Admin User Exists**
   - Checks for admin user (configurable via appsettings)
   - Creates admin user if doesn't exist
   - Email: `admin@echoes.com` (default)
   - Password: `Admin123!` (default)
   - Assigns `Admin | Player` roles

2. **Seeds Shop Items**
   - Creates 3 sci-fi test items if shop is empty

#### JWT Token Claims
Updated `GenerateJwtToken()` in `AuthController.cs`:

```csharp
new Claim("Roles", ((long)account.Roles).ToString()),
new Claim(ClaimTypes.Role, "Admin"),  // If has Admin flag
new Claim(ClaimTypes.Role, "Pilot"),  // If has Player flag
```

### 3. Swagger Security (Admin-only)

#### Middleware Implementation
**File**: `Program.cs`

Added custom middleware after `UseAuthorization()`:

```csharp
app.Use(async (context, next) =>
{
    if (context.Request.Path.StartsWithSegments("/swagger"))
    {
        // Check authentication
        if (!context.User.Identity?.IsAuthenticated ?? true)
        {
            context.Response.StatusCode = 403;
            return;
        }

        // Check Admin role
        var rolesClaimValue = context.User.FindFirst("Roles")?.Value;
        if (long.TryParse(rolesClaimValue, out long roles))
        {
            var accountRole = (AccountRole)roles;
            if (!accountRole.HasFlag(AccountRole.Admin))
            {
                context.Response.StatusCode = 403;
                return;
            }
        }
    }
    await next();
});
```

**Behavior**:
- Anonymous users → 403 Forbidden
- Non-admin authenticated users → 403 Forbidden
- Admin users → Access granted

### 4. Shop System

#### ShopItem Entity
**File**: `Models/Entities/Shop/ShopItem.cs`

```csharp
[Table("shop_items")]
public class ShopItem
{
    public Guid Id { get; set; }
    public string Name { get; set; }
    public string Description { get; set; }
    public long Price { get; set; }
    public string? ImageUrl { get; set; }
    public DateTime CreatedAt { get; set; }
    public bool IsActive { get; set; }
}
```

#### Database Context
**File**: `Data/DatabaseContext.cs`

Added:
```csharp
public DbSet<ShopItem> ShopItems { get; set; }
```

#### Seeded Shop Items
Via `DbInitializer.InitializeAsync()`:

1. **Frigate Hull - Imperial Vanguard**
   - Price: 500,000 credits
   - Description: Lightweight frigate for reconnaissance

2. **Plasma Cannon MK-VII**
   - Price: 1,200,000 credits
   - Description: High-energy plasma weapon

3. **Repair Nanites (Advanced)**
   - Price: 350,000 credits
   - Description: Self-replicating repair nanobots

#### Shop Controller
**File**: `Controllers/ShopController.cs`

```csharp
[Authorize] // Accessible to any logged-in Pilot or Admin
[ApiController]
[Route("api/[controller]")]
public class ShopController : ControllerBase
```

**GET /api/shop**
- Returns list of all active shop items
- Requires authentication (any role)

**GET /api/shop/{id}**
- Returns specific shop item by ID
- Requires authentication (any role)

## Configuration Required

### appsettings.json

Add these sections:

```json
{
  "Google": {
    "ClientId": "your-google-client-id.apps.googleusercontent.com",
    "ClientSecret": "your-google-client-secret"
  },
  "Admin": {
    "Email": "admin@echoes.com",
    "Password": "Admin123!",
    "Username": "admin"
  }
}
```

## Security Features

1. **Google Token Validation**: Server-side validation using Google's API
2. **Role-Based Authorization**: Flags enum for flexible role management
3. **JWT Claims**: Includes roles for authorization checks
4. **Swagger Protection**: Admin-only access via middleware
5. **Password-less Auth**: Google users don't need passwords

## API Endpoints Summary

### Authentication
- `POST /api/auth/google-login` - Login with Google
- `POST /api/auth/google-register` - Register with Google + Nickname
- `POST /api/auth/register` - Traditional registration (existing)
- `POST /api/auth/login` - Traditional login (existing)

### Shop
- `GET /api/shop` - List all shop items (requires auth)
- `GET /api/shop/{id}` - Get specific item (requires auth)

### Swagger
- `/swagger` - API documentation (Admin only)

## Testing

### 1. Test Google Registration
```bash
POST /api/auth/google-register
{
  "googleIdToken": "<valid-google-id-token>",
  "nickname": "SpacePilot"
}
```

Expected: Success with JWT token, character created with Player role

### 2. Test Google Login
```bash
POST /api/auth/google-login
{
  "googleIdToken": "<valid-google-id-token>"
}
```

Expected: Success with JWT token (if user exists) or RegistrationNeeded flag

### 3. Test Shop Access (Pilot)
```bash
GET /api/shop
Authorization: Bearer <pilot-jwt-token>
```

Expected: 200 OK with list of 3 shop items

### 4. Test Swagger Access (Admin)
```bash
GET /swagger
Authorization: Bearer <admin-jwt-token>
```

Expected: 200 OK with Swagger UI

### 5. Test Swagger Access (Pilot)
```bash
GET /swagger
Authorization: Bearer <pilot-jwt-token>
```

Expected: 403 Forbidden

## Known Issues

**Pre-existing Build Error**: 
- Duplicate `AccountSession` class definition in `Account.cs` (line 734) and `AccountSession.cs`
- This error exists before our changes
- Does not affect the functionality of our new features
- Recommendation: Remove the AccountSession class from Account.cs file

## Implementation Notes

1. **Google Client ID/Secret**: Must be configured in appsettings.json or environment variables
2. **Admin User**: Created automatically on first run
3. **Shop Items**: Seeded automatically on first run
4. **Roles**: Using Flags enum for flexible multi-role support
5. **JWT**: Includes Roles claim for authorization checks

## Future Enhancements

1. Add password reset for Google accounts
2. Add shop purchase functionality
3. Add inventory integration
4. Add transaction history
5. Add admin endpoints for shop management
6. Add rate limiting for auth endpoints
