# Pilot Dashboard Implementation

## Overview
This implementation adds a "Pilot Dashboard" feature to the Echoes of Imperial game, allowing authenticated users to view their pilot's information through a protected API endpoint and a futuristic HUD-style interface.

## Components

### 1. Data Transfer Object (DTO)
**File**: `EchoesOfImperial.Shared/DTOs/PilotDashboardDTO.cs`

```csharp
public class PilotDashboardDTO
{
    public Guid PilotId { get; set; }
    public string PilotName { get; set; }
    public string CorpName { get; set; } = "Freelancer";
    public long Credits { get; set; }
    public string CurrentSystem { get; set; } = "Jita";
    public string CurrentShip { get; set; } = "Ibis";
}
```

This DTO defines the structure of pilot data that is transferred between the API and the Blazor client.

### 2. API Controller
**File**: `Controllers/PilotController.cs`

#### Key Features:
- **[Authorize]** attribute ensures only authenticated users with valid JWT tokens can access the endpoint
- Extracts user and character IDs from JWT token claims
- Queries the database for character information
- Returns pilot dashboard data or appropriate error responses

#### Endpoint:
- **GET** `/api/pilot/dashboard`
- **Authentication**: Required (JWT Bearer token)
- **Response**: `PilotDashboardDTO` with pilot information

#### Implementation Details:
1. Extracts `sub` (user ID) and `CharacterId` from JWT claims
2. Queries the database for the character with the given IDs
3. Fetches current system name from the database
4. Returns structured pilot data

### 3. Authorization Message Handler
**File**: `EchoesOfImperial.Client/Services/AuthorizationMessageHandler.cs`

This custom `DelegatingHandler` automatically attaches JWT tokens to all HTTP requests made by the Blazor client.

#### How It Works:
1. Intercepts all outgoing HTTP requests
2. Retrieves the stored JWT token from browser's local storage
3. Adds the token to the `Authorization` header as a Bearer token
4. Passes the request to the next handler in the pipeline

### 4. Client Configuration
**File**: `EchoesOfImperial.Client/Program.cs`

Updated to configure the HttpClient with the custom authorization handler:

```csharp
// Add custom authorization message handler
builder.Services.AddScoped<AuthorizationMessageHandler>();

// Configure HttpClient with authorization handler
builder.Services.AddScoped(sp =>
{
    var handler = sp.GetRequiredService<AuthorizationMessageHandler>();
    handler.InnerHandler = new HttpClientHandler();
    
    var httpClient = new HttpClient(handler)
    {
        BaseAddress = new Uri("https://localhost:5115")
    };
    
    return httpClient;
});
```

### 5. Blazor Dashboard UI
**File**: `EchoesOfImperial.Client/Pages/Dashboard.razor`

#### Features:
1. **Loading State**: Displays "SCANNING NEURAL LINK..." with animated pulse ring
2. **HUD Display**: Shows pilot data in a futuristic Head-Up Display layout
3. **Error Handling**: Shows error messages with retry functionality
4. **Authentication Check**: Redirects to login if user is not authenticated

#### UI Layout:
- **Header**: Pilot name, corporation name, and credits
- **Body**: Current system location and active ship
- **Footer**: Neural link status indicator

#### Styling:
- Dark theme with gold accents (#d4af37)
- Sci-Fi aesthetic with glowing effects and animations
- CSS Grid for responsive layout
- Animated loading and status indicators
- Responsive design for mobile devices

## Security Features

1. **JWT Authentication**: All API requests require a valid JWT token
2. **Claim-Based Authorization**: User and character IDs are extracted from JWT claims
3. **Automatic Token Attachment**: Tokens are automatically added to requests by the message handler
4. **Session Expiration Handling**: Redirects to login when token expires

## User Flow

1. User logs in and receives JWT token
2. Token is stored in browser's local storage
3. User navigates to `/dashboard`
4. Dashboard checks authentication status
5. If authenticated, displays loading animation
6. HttpClient automatically attaches JWT token to API request
7. API validates token and extracts user/character IDs
8. API queries database for character data
9. API returns pilot dashboard data
10. Dashboard displays data in HUD interface

## Error Handling

- **Unauthorized (401)**: Redirects to login page
- **Not Found (404)**: Shows error that pilot was not found
- **Network Errors**: Displays connection error with retry button
- **General Errors**: Shows error message with retry functionality

## Database Integration

The controller queries the following database entities:
- `Characters`: Main pilot/character data
- `SolarSystems`: Current location information
- Navigation properties via Entity Framework Core

## Future Enhancements

The implementation includes placeholders for future features:
- **Corporation System**: Currently defaults to "Freelancer"
- **Ship System**: Currently defaults to "Ibis"
- **Additional Stats**: Security status, clone info, etc.

## Testing

To test the implementation:

1. Start the API server
2. Start the Blazor client
3. Register/Login to get a JWT token
4. Navigate to `/dashboard`
5. Verify that pilot data is displayed correctly
6. Test error scenarios (expired token, network errors, etc.)

## API Documentation

The endpoint is documented in Swagger UI at `/swagger` when running in development mode. The `[Authorize]` attribute adds a lock icon in Swagger, and users must provide a Bearer token to test the endpoint.

## Compatibility

- .NET 8.0
- ASP.NET Core Web API
- Blazor WebAssembly
- Entity Framework Core
- PostgreSQL (or InMemory for development)
