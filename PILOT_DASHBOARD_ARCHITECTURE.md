# Pilot Dashboard Architecture

## Request Flow Diagram

```
┌─────────────────────────────────────────────────────────────────────┐
│                         USER INTERACTION                            │
└─────────────────────────────────────────────────────────────────────┘
                                 │
                                 ▼
┌─────────────────────────────────────────────────────────────────────┐
│                    Dashboard.razor (Blazor Page)                    │
│  • Check if user is authenticated                                   │
│  • Display loading animation                                        │
│  • Call API to fetch pilot data                                     │
│  • Display HUD with pilot information                               │
└─────────────────────────────────────────────────────────────────────┘
                                 │
                                 ▼
┌─────────────────────────────────────────────────────────────────────┐
│              AuthorizationMessageHandler (Middleware)               │
│  • Intercept HTTP request                                           │
│  • Retrieve JWT token from LocalStorage                             │
│  • Attach token to Authorization header                             │
└─────────────────────────────────────────────────────────────────────┘
                                 │
                                 ▼
┌─────────────────────────────────────────────────────────────────────┐
│                    HTTP Request to API                              │
│  GET /api/pilot/dashboard                                           │
│  Authorization: Bearer <JWT_TOKEN>                                  │
└─────────────────────────────────────────────────────────────────────┘
                                 │
                                 ▼
┌─────────────────────────────────────────────────────────────────────┐
│                PilotController (API Endpoint)                       │
│  • Validate JWT token ([Authorize] attribute)                       │
│  • Extract user ID and character ID from claims                     │
│  • Query database for character data                                │
│  • Fetch current system information                                 │
│  • Return PilotDashboardDTO                                         │
└─────────────────────────────────────────────────────────────────────┘
                                 │
                                 ▼
┌─────────────────────────────────────────────────────────────────────┐
│                    Database (PostgreSQL)                            │
│  • Characters table                                                 │
│  • SolarSystems table                                               │
│  • Navigation properties                                            │
└─────────────────────────────────────────────────────────────────────┘
```

## Data Flow

### 1. Frontend (Blazor)
```
Dashboard.razor
    ├── OnInitializedAsync()
    │   └── LoadDashboard()
    │       ├── Check authentication
    │       ├── Show loading state
    │       ├── Call HTTP GET /api/pilot/dashboard
    │       └── Display data or error
    └── HUD Interface
        ├── Header (Name, Corp, Credits)
        ├── Body (Location, Ship)
        └── Footer (Status)
```

### 2. HTTP Layer
```
HttpClient
    └── AuthorizationMessageHandler
        ├── Read token from LocalStorage
        ├── Add to Authorization header
        └── Send request
```

### 3. Backend (API)
```
PilotController
    ├── [Authorize] - JWT validation
    ├── GetDashboard()
    │   ├── Extract claims (sub, CharacterId)
    │   ├── Query Characters
    │   ├── Query SolarSystems
    │   └── Build PilotDashboardDTO
    └── Return response
```

## Security Layers

1. **Authentication**: JWT token required for API access
2. **Authorization**: [Authorize] attribute on controller
3. **Claim Verification**: User ID and Character ID extracted from token
4. **Database Validation**: Verify character belongs to user
5. **Automatic Token Management**: Handler attaches token to all requests

## Component Relationships

```
┌────────────────────────────────────────────────────────────┐
│                    EchoesOfImperial.Shared                 │
│  • PilotDashboardDTO (shared data structure)               │
└────────────────────────────────────────────────────────────┘
         ▲                                          ▲
         │                                          │
         │                                          │
┌────────┴─────────────────┐         ┌─────────────┴──────────┐
│  EchoesOfImperial.Client │         │      Echoes.API        │
│  • Dashboard.razor       │         │  • PilotController     │
│  • AuthorizationHandler  │         │  • DatabaseContext     │
│  • AuthService           │         │  • JWT Middleware      │
│  • HttpClient            │◄───────►│  • [Authorize]         │
└──────────────────────────┘         └────────────────────────┘
```

## UI States

### Loading State
- Animated pulse ring
- "SCANNING NEURAL LINK..." text
- Blinking animation

### Success State (HUD Display)
- Gold/Dark theme (#d4af37)
- CSS Grid layout
- Pilot name (large, gold)
- Corporation name
- Credits (monospace, formatted)
- Current system
- Current ship
- Status indicator (green pulsing dot)

### Error State
- Red theme
- Warning icon
- Error message
- Retry button

## CSS Architecture

```
dashboard-container (full viewport)
    ├── loading-screen
    │   └── neural-link
    │       ├── pulse-ring (@keyframes pulse)
    │       └── scanning-text (@keyframes blink)
    │
    ├── hud-display
    │   ├── hud-header (grid: 2 columns)
    │   │   ├── pilot-info (left)
    │   │   │   ├── pilot-name (gold, large)
    │   │   │   └── corp-name
    │   │   └── credits-display (right)
    │   │       ├── credits-label
    │   │       └── credits-value (monospace)
    │   │
    │   ├── hud-body (grid: 2 columns)
    │   │   ├── info-panel (location)
    │   │   └── info-panel (ship)
    │   │
    │   └── hud-footer
    │       └── status-indicator
    │           ├── status-dot (@keyframes pulse-dot)
    │           └── status-text
    │
    └── error-display
        ├── error-icon
        ├── error-text
        └── retry-button
```
