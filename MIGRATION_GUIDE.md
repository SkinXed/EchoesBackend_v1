# Server Controller Refactoring - Migration Guide

## Overview
The server-related endpoints have been reorganized into two separate controllers for better separation of concerns:
- **ServerManagementController**: Server administration operations
- **GameServerController**: Gameplay/client operations

## Breaking Changes

### Route Changes
The base route for management endpoints has changed from `/api/gameserver` to `/api/server-management`.

### Old → New Endpoint Mapping

#### Management Endpoints (Server Administration)
| Old Endpoint | New Endpoint | Notes |
|-------------|--------------|-------|
| `POST /api/gameserver/register` | `POST /api/server-management/register` | Server registration |
| `POST /api/gameserver/heartbeat` | `POST /api/server-management/heartbeat` | Server heartbeat |
| `DELETE /api/gameserver/unregister/{instanceId}` | `DELETE /api/server-management/unregister/{instanceId}` | Server unregistration |
| `GET /api/gameserver/stats` | `GET /api/server-management/stats` | Server statistics |
| `GET /api/gameserver/list` | `GET /api/server-management/list` | Server list with filters |

#### Gameplay Endpoints (Client Operations)
These endpoints remain at `/api/gameserver` but are now in a separate controller:
| Endpoint | Notes |
|----------|-------|
| `GET /api/gameserver/systems/{systemId}` | Get solar system data |
| `GET /api/gameserver/for-system/{systemId}` | Get connection info for system |
| `POST /api/gameserver/request-connection` | Request connection to system |
| `GET /api/gameserver/handshake` | Health check / API status |

## Migration Steps

### For Game Server Applications
Update your registration and heartbeat calls:

**Old:**
```csharp
POST /api/gameserver/register
POST /api/gameserver/heartbeat
DELETE /api/gameserver/unregister/{instanceId}
```

**New:**
```csharp
POST /api/server-management/register
POST /api/server-management/heartbeat
DELETE /api/server-management/unregister/{instanceId}
```

### For Admin/Monitoring Tools
Update server list and statistics endpoints:

**Old:**
```csharp
GET /api/gameserver/list
GET /api/gameserver/stats
```

**New:**
```csharp
GET /api/server-management/list
GET /api/server-management/stats
```

### For Game Clients
No changes required - gameplay endpoints remain at the same routes.

## Improved Features

### 1. Better Error Handling
All endpoints now have consistent error responses:
```json
{
  "success": false,
  "error": "Error description"
}
```

### 2. Enhanced Documentation
All endpoints and DTOs now include XML documentation visible in Swagger/OpenAPI.

### 3. Improved Type Safety
All DTOs include data validation attributes and better nullability handling.

### 4. New Response DTOs
- `ServerStatsResponse`: Structured server statistics
- `ServerListResponse`: Paginated server list with metadata

## Example Code Updates

### C# Client Example
**Before:**
```csharp
var response = await httpClient.PostAsync(
    "https://api.example.com/api/gameserver/register", 
    content);
```

**After:**
```csharp
var response = await httpClient.PostAsync(
    "https://api.example.com/api/server-management/register", 
    content);
```

### JavaScript/TypeScript Client Example
**Before:**
```javascript
const response = await fetch('/api/gameserver/register', {
    method: 'POST',
    body: JSON.stringify(registrationData)
});
```

**After:**
```javascript
const response = await fetch('/api/server-management/register', {
    method: 'POST',
    body: JSON.stringify(registrationData)
});
```

## Rollback Plan
If issues arise, you can temporarily route requests to both old and new endpoints by:
1. Creating a proxy/redirect from old routes to new routes
2. Updating clients gradually
3. Monitoring for any errors

## Testing Recommendations
1. Test server registration flow
2. Verify heartbeat mechanism works
3. Check server list endpoint with filters
4. Validate gameplay connection requests
5. Ensure statistics endpoint returns correct data

## Support
If you encounter issues during migration, please:
1. Check the server logs for detailed error information
2. Verify your request payloads match the new DTO structures
3. Ensure you're using the correct endpoint routes
